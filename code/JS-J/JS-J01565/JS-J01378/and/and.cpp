#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],t;
bool b[200005][35],f[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    t=n-m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int aa=a[i];
        for(int j=0;j<=30;j++){
            b[i][j]=aa%2;
            aa/=2;
        }
    }
    for(int i=30;i>=0;i--){
        int s=0;
        for(int j=1;j<=n;j++){
            if(f[j]==0&&b[j][i]==0) s++;
        }
        if(s>=1&&s<=t){
            for(int j=1;j<=n;j++){
                if(f[j]==0&&b[j][i]==0) f[j]=1,t--;
            }
        }
    }
    int sum=0,ans=-1;
    for(int i=1;i<=n;i++){
        if(f[i]==0&&sum<m){
            sum++;
            if(ans==-1) ans=a[i];
                else ans&=a[i];
        }
    }
    cout<<ans;
    return 0;
}
