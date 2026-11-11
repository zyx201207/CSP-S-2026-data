#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5009,M=2e6+9;
const ll INF=1e18;
int a;
ll c,t,n,d,x[M],_dis[M],_cnt[M],_num[M],dis[N][N],cnt[N][N],num[N][N];
deque<ll>q;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=10){
        while(t--){
            ll ans=0;
            cin>>n>>d;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    cnt[i][j]=num[i][j]=dis[i][j]=0;
                }
            }
            for(int i=1;i<=n;++i)cin>>x[i];
            for(int i=1;i<=n;++i){
                while(!q.empty())q.pop_front();
                q.push_front(i),cnt[i][0]=1;
                for(int j=i+1;j<=n;++j){
                    while(!q.empty()&&x[j]-x[q.front()]>d)cnt[i][dis[i][q.front()]]-=num[i][q.front()],q.pop_front();
                    if(q.empty())break;
                    if(cnt[i][dis[i][q.front()]]==2)ans++;
                    dis[i][j]=dis[i][q.front()]+1,cnt[i][dis[i][j]]+=cnt[i][dis[i][q.front()]];
                    num[i][j]=cnt[i][dis[i][q.front()]];
                    while(!q.empty()&&dis[i][q.back()]>dis[i][j])cnt[i][dis[i][q.back()]]-=num[i][q.back()],q.pop_back();
                    q.push_back(j);
                }
            }
            cout<<ans<<"\n";
        }
    }
    else{
        while(t--){
            ll ans=0;
            cin>>n>>d;
            for(int j=1;j<=n;++j){
                _cnt[j]=_num[j]=_dis[j]=0;
            }
            for(int i=1;i<=n;++i)cin>>x[i];
            while(!q.empty())q.pop_front();
            q.push_front(1),_cnt[0]=1;
            for(ll j=2;j<=n;++j){
                while(!q.empty()&&x[j]-x[q.front()]>d)_cnt[_dis[q.front()]]-=_num[q.front()],q.pop_front();
                if(q.empty())break;
                _dis[j]=_dis[q.front()]+1,_cnt[_dis[j]]+=_cnt[_dis[q.front()]];
                _num[j]=_cnt[_dis[q.front()]];
                while(!q.empty()&&_dis[q.back()]>_dis[j])_cnt[_dis[q.back()]]-=_num[q.back()],q.pop_back();
                q.push_back(j);
            }
            for(int i=1;i<=n;++i){
                if(_num[i]==2)_num[i]=_num[i-1]+1;
                else _num[i]=_num[i-1];
                ans+=_num[i];
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
