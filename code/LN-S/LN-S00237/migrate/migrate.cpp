#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
struct Node{
    long long num=0,stp=N;
}road[N];
int c,t;
int n;
long long d,x[N];
queue<Node> qu;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=N;i++) road[i]={0,N};
        long long ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        qu.push({1,1});
        while(!qu.empty()){
            Node frontt=qu.front();
            if(road[frontt.num].stp>=frontt.stp)
                if(road[frontt.num].stp==frontt.stp) road[frontt.num].num++;
                else road[frontt.num].num=1,road[frontt.num].stp=frontt.stp;
            long long head=frontt.num;
            long long step=frontt.stp+1;
            qu.pop();
            for(int i=head+1;i<=n;i++)
                if(x[i]-x[head]>d) break;
                else qu.push({i,step});
        }
        for(int i=1;i<=n;i++) if(road[i].num==2) ans++;
        cout<<ans<<endl;
    }
    return 0;
}

