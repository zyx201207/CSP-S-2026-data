#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const int num = 1000005;
const int inf = 1e15;
int T,n,k,d[num],dep[num],dis[num];
vector<int> v[num],r[num];
void solveA(){
    cin >> n >> k;
    F(i,1,n-1){
        int x,y;
        cin>>x>>y;
    }
    n/=2;
    n = (n + 1) / 2;
    k /= 2;
    // cerr << n << ' ' << k << endl;
    int ans = (n - k + 1) / 2+1;
    cout << ans << endl;
}
void ope(int x,int fa,int de){
    dis[x]=min(dis[x],de);
    for(int i:v[x])if(i!=fa){
        ope(i, x, de + 1);
    }
}
bool ck(int d){
    if(r[d+1].size()>2){
        
        return 0;
    }
    if(r[d+1].size()==0)return 1;
    // cerr << d + 1 << endl;
    F(i,1,n)dis[i] = inf;
    for(int i:r[d+1]){
        // cerr << i << endl;
        ope(i,0,0);
    }
    F(i, 1, n)
        if (dis[i] > d) return 0;
    return 1;
}
void solveB(){
    cin >> n >> k;
    F(i, 1, n){
        v[i].clear();
        r[i].clear();
        dep[i] = d[i] = 0;
    }
    F(i,1,n-1){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        d[x]++;
        d[y]++;
    }
    queue<pii>q;
    F(i,1,n){
        if(d[i]==1){
            dep[i]=1;
            q.push(pii(i, 1));
        }
    }
    while(!q.empty()){
        pii pi = q.front();
        q.pop();
        int x = pi.fi;
        for(int i:v[x])if(!dep[i]){
            d[i]--;
            if(d[i]==1){
                dep[i] = pi.se + 1;
                q.push(pii(i, dep[i]));
            }
        }
    }
    F(i, 1, n){
        // cerr << dep[i] << endl;
        r[dep[i]].pb(i);
    }
    int l = 1, r = n,ans=n;
    while(l<=r){
        int mid = (l + r) >> 1;
        if(ck(mid)){
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int C;
    cin>>C>>T;
    
    while(T--){
        if(C==13||C==14){
            solveA();
        }
        else
            solveB();
    }
    
}