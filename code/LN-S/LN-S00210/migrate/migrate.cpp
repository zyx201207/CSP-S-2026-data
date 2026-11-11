#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


const int N=1e5+10;
int n,m;
long long d;
long long a[N];
vector<int> g[N];
int flag[N];

int ways[N];

#define lowbit(x) ((x)&(-x))

int sg[N];

void modify(int pos,int val){
    for(int x=pos;x<=n;x+=lowbit(x)){
        sg[x]+=val;
    }
}

int query(int pos){
    int res=0;
    for(int x=pos;x>0;x-=lowbit(x)){
        res += sg[x];
    }
    return res;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin >> c>> T;
    while(T--){
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            sg[i]=0;
            cin >> a[i];
            // modify(i,a[i]);
            // modify(i+1,-a[i]);
        }
        // for(int i=1;i<=n;i++){
        //     cout << query(i) << endl;
        // }
        int last_modify_num = -1;
        for(int i=1;i<=n;i++){
            if(last_modify_num != -1 && i <= last_modify_num && last_modify_num+1<=n){
                modify(i+1,-1);
                modify(last_modify_num+1,1);
            }
            int pos = lower_bound(a+1,a+1+n,a[i]+d)-a+1;
            modify(i+1,1);
            if(pos+1<=n){
                modify(pos+1,-1);
            }
            last_modify_num = pos;
            // cout << "Mod " << i+1 << " " << pos+1 << endl;
            // for(int i=1;i<=n;i++){
            //     cout << query(i) << " ";
            // }
            // cout? << endl;
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            if(query(i)==2){
                sum++;
            }
            // cout << query(i) << endl;
        }
        // cout << endl;
        cout << sum << endl;
        // cout << endl;
    }
}