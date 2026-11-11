#include<bits/stdc++.h>
using namespace std;
int C,T;
long long x[200000];
int qs[200000][2];
long long s[200000][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        memset(x,0,sizeof(x));
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            memset(s,0,sizeof(s));
            memset(qs,0,sizeof(qs));
            queue<int> q;
            int lqs=1;
            qs[lqs++][0]=i;
            q.push(1);
            while(!q.empty()){
                int a=q.front();
                q.pop();
                for(int j=qs[a][0]+1;j<=n;j++){
                    if(x[j]-x[qs[a][0]]<=d){
                        if(s[j][0]==0){
                            s[j][0]=qs[a][1]+1;
                            s[j][1]++;
                        }
                        else if(qs[a][1]+1==s[j][0]){
                            if(s[j][1]<3)s[j][1]++;
                            if(s[j][1]>=3)continue;
                        }
                        else continue;
                        qs[lqs][0]=j;
                        qs[lqs][1]=qs[a][1]+1;
                        q.push(lqs);
                        lqs++;
                    }
                    else break;
                }
            }
            for(int j=i+1;j<=n;j++){
                if(s[j][1]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
