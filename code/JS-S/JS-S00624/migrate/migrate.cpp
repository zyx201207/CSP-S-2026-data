#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e6+10;

int C,T;
int n,d;
int a[N];
int ans;

void init(){
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
    ans=0;
}

void bfs1(int st,int ed){
    int cnt=0;
    queue<pair<int,int>> q;
    q.push({st,0});
    int mi=0x3f3f3f3f;
    while(!q.empty()){
        int u=q.front().first;
        int step=q.front().second;
        q.pop();
        if(u==ed){
            if(step<=mi){
                mi=step;
                cnt++;
            }else{
                break;
            }
        }
        if(cnt>2)break;
        for(int i=u+1;i<=ed;i++){
            if(a[i]-a[u]>d)break;
            q.push({i,step+1});
        }
    }
    if(cnt==2){
        ans++;
    }
}

void solve1(){
    for(int i=1;i<=n-3;i++){
        for(int j=i+3;j<=n;j++){
            bfs1(i,j);
        }
    }
    cout<<ans<<"\n";
}

void solve2(){
    int ca=a[2]-a[1];
    if(ca>=d){
        cout<<0<<endl;
    }else if(2*ca>=d){
        if(n<=3){
            cout<<0<<endl;
        }else{
            cout<<n-3<<endl;
        }
    }else{
        cout<<0<<endl;
    }
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        scanf("%lld%lld",&n,&d);
        init();
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(C<=6){
            solve1();
        }

        if(C==11||C==12){
            solve2();
        }
    }
    return 0;
}
