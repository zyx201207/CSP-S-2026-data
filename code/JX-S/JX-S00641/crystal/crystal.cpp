#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,sum;
int a[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int g=n,h=m;
    sort(a+1,a+1+g);
    for(int j=2;j<=g;j++){
        m=h;
        ans=0;
        int d=a[j];
        int i=j-1;

        while(m>=0&&i>0){
            int f=d-a[i];
            i--;
            if(m-f>=0){
                ans++;
            }
            m-=f;
        }
        for(int i=j;i<=g;i++){
            if(a[i]==a[j]){
                ans++;
            }
        }
        sum=max(sum,ans);
    }
    cout<<sum;
    return 0;
}
