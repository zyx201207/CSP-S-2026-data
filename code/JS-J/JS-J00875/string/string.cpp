#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<char> alphas;
vector<ll> nums;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;char b;
        cin>>a>>b;
        if(i==0){
            alphas.push_back(b);
            nums.push_back(a);
            continue;
        }
        if(alphas[alphas.size()-1]==b){
            nums[nums.size()-1]+=a;
        }else{
            alphas.push_back(b);
            nums.push_back(a);
        }
    }ll changes=0,l=0,r=alphas.size()-1;
    /*for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<alphas[i]<<endl;
    }*/
    while(l<r){
        //cout<<"Now l:"<<l<<" r:"<<r<<endl;
        if(alphas[l]==alphas[r]){
            //cout<<"alpha same\n";
            //cout<<nums[l]<<' '<<nums[r]<<endl;
            if(nums[l]>nums[r]){
                //cout<<"l>r\n";
                nums[l]-=nums[r];
                r--;
            }else if(nums[l]<nums[r]){
                //cout<<"l<r\n";
                nums[r]-=nums[l];
                l++;
            }else{
                //cout<<"l=r\n";
                r--;l++;
            }
        }else{
            //cout<<"alpha unsame\n";
            //cout<<nums[l]<<' '<<nums[r]<<endl;
            if(nums[l]>nums[r]){
                changes+=nums[r];
                nums[l]-=nums[r];
                r--;
            }else if(nums[l]<nums[r]){
                //cout<<"l<r\n";
                changes+=nums[l];
                nums[r]-=nums[l];
                l++;
            }else{
                //cout<<"l=r\n";
                changes+=nums[r];
                r--;l++;
            }
        }
    }cout<<changes;
    return 0;
}
