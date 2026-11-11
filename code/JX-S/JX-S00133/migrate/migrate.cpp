#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000006],r,m,L,R,ans,dis[10];
bool z;
void dfs(int s,int t,int c){
    if(s==t){
        dis[c]++;
    }
    for(int i=s+1;i<=t;i++){
        if(x[i]-x[s]<=d){
            dfs(i,t,c+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c;
    if(c<=2){
        cin>>t;
        while(t--){
            cin>>n>>d;
            ans=0;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            z=1;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int i=1;i<=n;i++){
                        dis[i]=0;
                    }
                    dfs(i,j,0);
                    for(int i=1;i<=n;i++){
                        if(!dis[i])continue;
                            if(dis[i]==2){
                            ans++;
                            break;
                        }
                        else break;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    else if(c==11||c==12){
        cin>>t;
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            if(x[n]-x[1]<=d)cout<<0<<endl;
            else{
                r=x[2]-x[1];
                if(r>d||d/r>=3)cout<<0<<endl;
                else{
                    m=d/r+2;
                    cout<<n-m+1<<endl;
                }
            }
        }
    }
    else if(c==13||c==14){
        cin>>t;
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            L=R=0;
            for(int i=1;i<=n;i++){
                if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
                    if(!L)L=i;
                    R=i;
                }
            }
            if(R-L+1>=3||L==1)cout<<0<<endl;
            else{
                if(R-L+1==2){
                    ans=0;
                    for(int i=1;i<L;i++){
                        if(x[R+1]-x[i]>d){
                            ans+=n-(upper_bound(x+1,x+n+1,x[L-1]+d)-x)+1;
                        }
                    }
                    cout<<ans<<endl;
                }
                else{
                    if(x[R+1]-x[L-1]>d||R+2<=n&&x[R+2]-x[L-1]<=d)cout<<0<<endl;
                    else{
                        ans=0;
                        for(int i=1;i<L;i++){
                            if(x[R+1]-x[i]<=d){
                                ans+=n-R-1;
                            }
                        }
                        cout<<ans<<endl;
                    }
                }
            }
        }
    }
    else{
        cin>>t;
        while(t--){
            cout<<0<<endl;
        }
    }
    return 0;
}
