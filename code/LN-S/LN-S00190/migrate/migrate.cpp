#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
long long ans[2000005];
long long check=1;
long long way=0;
void bfs(long long st,long long ed,long long step){
    if(st==ed){
        ans[check]=step;
        check++;
        return ;
    }
    for(long long i=st+1;i<=ed;i++){
        long long cha=x[i]-x[st];
        if(cha<=d){
            bfs(i,ed,step++);
        }
    }
    return ;
}
bool cpp(long long a,long long b){
    return a>b;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(long long i=1;i<=n;i++) cin>>x[i];
        for(long long i=1;i<=n-3;i++){
            for(long long j=i+3;j<=n;j++){
                bfs(i,j,1);
                sort(ans+1,ans+check+1,cpp);
                if(ans[1]==ans[2]&&ans[2]!=ans[3]) way++;
                for(long long q=1;q<=check;q++) ans[q]=0;
                check=0;
            }
        }
        cout<<way<<endl;
        way=0;
    }
    return 0;
}
