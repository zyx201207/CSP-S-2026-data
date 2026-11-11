#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,len,w,maxn=-1e9,a[500005],l,s,man;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s=i;
        if(len*(a[i]-maxn)+w<=m){
            w+=len*(a[i]-maxn);
            len++;
            maxn=a[i];
            ans=max(ans,len);
        }
        else{
            w+=len*(a[i]-maxn);
            len++;
            maxn=a[i];
            for(int j=l;j<i;j++){
                w-=(a[i]-a[j]);
                len--;
                l++;
                if(w<=m){
                    break;
                }
            }
            ans=max(ans,len);
        }
    }
    cout<<ans;
    return 0;
}
