#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[305];
int num[305][305];
int dis[305][305];
 main(){
     freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    int c,T;
    cin>>c>>T;
    if(c==1||c==2||c==0){
        while(T--){
            memset(dis,0x3f,sizeof(dis));
            memset(num,0,sizeof(num));
            int n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            for(int i=1;i<(1<<n);i++){
                if(__builtin_popcount(i)<=1)continue;
                int fit;
                int end;
                for(int j=1;j<=n;j++){
                    if(i&(1<<j-1)){
                        fit=j;
                        break;
                    }
                }
                for(int j=n;j>=1;j--){
                    if(i&(1<<j-1)){
                        end=j;
                        break;
                    }
                }
                bool flag=true;
                int lst=fit;
                for(int j=fit+1;j<=end;j++){
                    if(i&(1<<j-1)){
                        if(x[j]-x[lst]>d){
                            flag=false;
                            break;
                        }
                        lst=j;
                    }
                }
                if(flag){
                    if(__builtin_popcount(i)-1<dis[fit][end]){
                        dis[fit][end]=__builtin_popcount(i)-1;
                        num[fit][end]=1;
                    }
                    else if(__builtin_popcount(i)-1==dis[fit][end]){
                        num[fit][end]++;
                    }
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(num[i][j]==2){
                        ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    if(c==3){
        while(T--){
            memset(dis,0x3f,sizeof(dis));
            memset(num,0,sizeof(num));
            int n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            for(int i=1;i<=n;i++)dis[i][i]=0,num[i][i]=1;
            for(int len=2;len<=n;len++){
                for(int i=1;i+len-1<=n;i++){
                    int j=i+len-1;
                    for(int k=i+1;k<=j;k++){
                        if(x[k]-x[i]<=d){
                            dis[i][j]=min(dis[i][j],1+dis[k][j]);
                        }
                    }
                }
            }
            for(int len=2;len<=n;len++){
                for(int i=1;i+len-1<=n;i++){
                    int j=i+len-1;
                    for(int k=i+1;k<=j;k++){
                        if(x[k]-x[i]<=d&&1+dis[k][j]==dis[i][j]){
                            num[i][j]+=num[k][j];
                        }
                    }
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(num[i][j]==2){
                        cnt++;
                    }
                }
            }
            cout<<cnt<<"\n";
        }
        
    }
    return 0;
}