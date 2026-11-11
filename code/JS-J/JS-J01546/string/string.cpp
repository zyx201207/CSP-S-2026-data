#include <bits/stdc++.h>
using namespace std;
struct words{
    long long nums;
    char wod;
}s[200005];
int n;
long long replace_(int x,long long len1,long long st){
    long long sum = 0,ans = 0,canre = 0;
    for(int i=n;i>=1;i--){
        sum+=s[i].nums;
        if(sum>=st){
            if(sum-st+1<s[i].nums){
                canre = sum-st+1;
            }
            else{
                canre = s[i].nums;
            }
            if(s[i].wod!=s[x].wod){
                if(len1<=canre){
                    ans+=len1;
                }
                else{
                    ans+=canre;
                }
            }
            len1-=canre;
            if(len1<=0){
                return ans;
            }
        }
    }
}
int main(){
    /*freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);*/
    long long len = 0,num = 0,ans = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].nums>>s[i].wod;
        len+=s[i].nums;
    }
    for(int i=1;i<=n;i++){
        num+=s[i].nums;
        if(num>len/2){
            ans+=replace_(i,s[i].nums-num+len/2,num-s[i].nums+1);
            break;
        }
        ans+=replace_(i,s[i].nums,num-s[i].nums+1);
    }
    cout<<ans;
    return 0;
}
