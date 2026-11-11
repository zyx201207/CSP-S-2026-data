#include<bits/stdc++.h>
using namespace std;
int n,m,r[200005][22],a[200005],s[22],mp,ans,cnt,am;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];am=max(am,a[i]);}
    if(m==1){cout<<am;return 0;}
    if(n==m){
        for(int i=1;i<=n;i++){
            for(int p=1;a[i]!=0;p++){r[i][p]=a[i]%2;a[i]/=2;mp=max(mp,p);}
            for(int j=1;j<=mp;j++) if(r[i][j]==0) s[j]=1;
        }for(int i=mp;i>=1;i--) if(s[i]==0) ans+=pow(2,i-1);
        cout<<ans;return 0;
    }if(m==2){
        for(int i=1;i<=n;i++){
            for(int p=1;a[i]!=0;p++){r[i][p]=a[i]%2;a[i]/=2;mp=max(mp,p);}
        }for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                ans=0;
                for(int y=mp;y>=1;y--) if(r[i][y]==1&&r[j][y]==1) ans+=pow(2,y-1);
                cnt=max(cnt,ans);
            }
        }cout<<cnt;return 0;
    }if(m==n-1){
        for(int ii=1;ii<=n;ii++){
            ans=0;
            for(int i=1;i<=n;i++){
                if(ii==i){
                    for(int iii=1;iii<=22;iii++) r[i][iii]=1;
                    break;
                }for(int p=1;a[i]!=0;p++){r[i][p]=a[i]%2;a[i]/=2;mp=max(mp,p);}
                for(int j=1;j<=mp;j++) if(r[i][j]==0) s[j]=1;
            }for(int i=mp;i>=1;i--) if(s[i]==0) ans+=pow(2,i-1);
            cnt=max(cnt,ans);
        }cout<<cnt;return 0;
    }
    return 0;
}
