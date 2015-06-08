#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    //if the nums vector is sorted, we can do it in this way
    vector<int> twoSum2(vector<int>& nums, int target) {
        int first=nums.at(0);
        int second=nums.at(nums.size()-1);
        int i=0;
        int j=nums.size()-1;
        int sumtmp=nums.at(0)+nums.at(nums.size()-1);
        while(1){
            if(sumtmp<target)
                i++;
            else if(sumtmp>target)
                j--;
            else{
                vector<int> result;
                result.push_back(nums.at(i));
                result.push_back(nums.at(j));
                return result;
            }
        }
    }
    //time limited exceed
    vector<int> twoSum3(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int sumtmp=nums.at(i)+nums.at(j);
                if(sumtmp==target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m.insert(make_pair(nums.at(i),i));
        }
        cout<<m[2]<<endl;
        map<int,int>::iterator iter;
        for(int i=0;i<nums.size();i++){
            int firstnum=nums.at(i);
            int secondnum=target-firstnum;
            iter=m.find(secondnum);
            if(iter!=m.end()){
                if(firstnum==secondnum&&m.count(firstnum)==2){
                    result.push_back(m[firstnum]);
                    result.push_back(m[secondnum]);
                    break;
                }else if(firstnum!=secondnum){
                    result.push_back(m[firstnum]);
                    result.push_back(m[secondnum]);
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    vector<int> res=s.twoSum(nums,6);
    cout<<res.at(0)<<" "<<res.at(1)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
