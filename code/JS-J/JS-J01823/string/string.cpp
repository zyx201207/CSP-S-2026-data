#include<bits/stdc++.h>
using namespace std;
long long n,nums[200005],ans;
char lis[200005];
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> nums[i] >> lis[i];
    }
    int l=1,r=n;
    while(l<r){
        if(lis[l]==lis[r]){
            if(nums[l]<nums[r]){
                nums[r]-=nums[l];
                l++;
            }else if(nums[l]>nums[r]){
                nums[l]-=nums[r];
                r--;
            }else{
                l++;
                r--;
            }
        }else{
            if(nums[l]<nums[r]){
                ans+=nums[l];
                nums[r]-=nums[l];
                l++;
            }else if(nums[l]>nums[r]){
                ans+=nums[r];
                nums[l]-=nums[r];
                r--;
            }else{
                ans+=nums[l];
                l++;
                r--;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
