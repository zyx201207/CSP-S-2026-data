#include <bits/stdc++.h>
using namespace std;
vector<long long> nums;
vector <string> zifus;
int main(){
    ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n;
    cin >>n;
    
    for(long long i = 0;i<n;i++){
        string zifu = "";
        long long num=0;
        cin >> num >> zifu;
        nums.push_back(num);
        
        zifus.push_back(zifu);
        
        
        
        
    }








long long qian = nums[0];

long long hou=nums[nums.size()-1];
string qianfu= zifus[0];
string houfu=zifus[zifus.size()-1];

long long start=0;

long long end=zifus.size()-1;
long long ans=0;




while (start <end){
    if(qianfu != houfu){
        if (qian == hou){
            ans += qian;
            start++;
            end--;
            qian = nums[start];
            hou = nums[end];
            qianfu = zifus[start];
            houfu = zifus[end];
        }else{
            if(qian > hou){
                ans += hou;
                qian = qian - hou;
                end--;
                hou = nums[end];
                qianfu = zifus[start];
                houfu = zifus[end];
            }else{
                ans += qian;
                hou = hou-qian;
                start++;
                qian = nums[start];
                qianfu = zifus[start];
                houfu = zifus[end];
            }
        }
    }else{
        if (qian == hou){
            
            start++;
            end--;
            qian = nums[start];
            hou = nums[end];
                qianfu = zifus[start];
                houfu = zifus[end];
        }else{
            if(qian > hou){
               
                qian = qian - hou;
                end--;
                hou = nums[end];
                qianfu = zifus[start];
                houfu = zifus[end];
            }else{
                
                hou = hou-qian;
                start++;
                qian = nums[start];
                                qianfu = zifus[start];
                houfu = zifus[end];
            }
        }
    }
}
cout << ans;

return 0;

}
