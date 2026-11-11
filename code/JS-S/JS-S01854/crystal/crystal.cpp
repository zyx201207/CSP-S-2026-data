#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],b[10005][10005];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=10000){
        for(int i=1;i<=n;i++){
            for(int j=i;j>0;j--){
                b[i][j]=a[i]-a[j]+b[i][j+1];
                if(b[i][j]<=m){
                    ans=max(ans,i-j+1);
                }
                if(b[i][j]>m){
                    break;
                }
            }
        }
    }
    else{
        long long s[500005];
        s[1]=0;
        for(int i=2;i<=n;i++){
            s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
            if(s[i]>m){
                cout<<i-1;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}

