#include<bits/stdc++.h>
using namespace std;
int t,n,m,d,q,yi[510],p[510],cnt2,w[500010],k[100010],a[300010][1010],c[100010][1010],cnt,ans=INT_MAX,xi[510];
set<int> s;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>t>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>c[i][j];
        }
    }
    while(q--){
        ans=INT_MAX;
        int x,y;
        cin>>x>>y;
        int sum=w[x]+w[y];
        for(int i=1;i<=n;i++){
            int f1=0,f2=0,f3=0,f4=0;
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x)f1=1,f3=j;
                if(a[i][j]==y)f2=1,f4=j;
            }
            if(f1==1&&f1==f2){
                sum+=c[i][f3]+c[i][f4];
                ans=min(ans,sum);
                sum=w[x]+w[y];
            }
        }
        if(ans==INT_MAX){
            memset(xi,0,sizeof(xi));
            cnt=0;
            memset(yi,0,sizeof(yi));
            cnt2=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=k[i];j++){
                    if(a[i][j]==x){
                        xi[++cnt]=i;
                    }
                    if(a[i][j]==y){
                        yi[++cnt2]=i;
                    }
                }
            }
            for(int i=1;i<=cnt;i++){
                for(int j=1;j<=k[xi[cnt]];j++){
                    if(a[xi[cnt]][j]==x){
                            sum+=c[xi[cnt]][j];
                    }
                    s.insert(a[xi[cnt]][j]);
                    p[a[xi[cnt]][j]]=c[xi[cnt]][j];
                }
            }
            for(int i=1;i<=cnt2;i++){

                for(int j=1;j<=k[yi[cnt]];j++){
                    if(a[yi[cnt]][j]==y){
                            sum+=c[yi[cnt]][j];
                    }
                }
            }
            for(int i=1;i<=cnt2;i++){

                for(int j=1;j<=k[yi[cnt]];j++){
                    if(s.count(a[yi[cnt]][j])){
                        sum+=c[yi[cnt]][j]+p[a[yi[cnt]][j]];
                        ans=min(ans,sum);
                        sum-=c[yi[cnt]][j]+p[a[yi[cnt]][j]];
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
