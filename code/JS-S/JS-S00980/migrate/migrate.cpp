#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+10;

long long n,d;

long long x[N];
int idx = 0;
int h[N],e[N<<1],ne[N<<1];
long long w[N<<1];
long long dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int cnt[N];

void spfa(){
    memset(dist,0x3f,sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[t] + w[i] < dist[j]){
                cnt[j] = 1;
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            } else if(dist[t] + w[i] == dist[j]){
                cnt[j]++;
            }
        }
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int c,t;
    cin >> c >> t;
    while(t--){
        memset(h,-1,sizeof(h));
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(x[j]-x[i] > d) break;
                add(i,j,x[j]-x[i]);
            }
        }
        spfa();
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(cnt[i] == 2) res++;
        }
        cout << res-1 << '\n';
        for(int i = 1; i <= n; i++){
            st[i] = false;
            cnt[i] = 0;
        }
        idx = 0;
    }
    return 0;
}
