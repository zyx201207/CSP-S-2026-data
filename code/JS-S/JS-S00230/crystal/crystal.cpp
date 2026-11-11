#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500010];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        int need_num=0;
        while(a[i+1]==a[i]){
            i++;
        }
        for(int j=i;j>=1;j--){
            need_num+=a[i]-a[j];
            if(need_num>m){
                ans=max(ans,i-j-1);
                break;
            }
            if(j==1){
                ans=max(ans,i);
            }
        }
    }
    cout<<ans;
    return 0;
}
