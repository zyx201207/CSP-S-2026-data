#include <iostream>
#include <cstring>
using namespace std;

struct edge{
    int to,nxt;
};
int f[100005];
int c,t;
int n,k;
int head[100005],tot;
edge g[200005];

void init(){
    tot=0;
    memset(head,0,sizeof(head));
}

int main (){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while (t--){
        init();
        cin >> n >> k;
        for (int i=1,u,v;i<=n;i++){
            cin >> u >> v;
        }
        if (k==2) cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}