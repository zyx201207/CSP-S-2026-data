#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
#define pdd pair<double,double>
using ll = long long;
using namespace std;
constexpr int N = 114514 * 5;
int father[N];
int find_ac(int lil){
    if(lil == father[lil])return lil;
    else return father[lil];
}
void set_father(int lil,int lip){
    father[lil] = find_ac(lip);
    father[lip] = father[lil];
}
bool if_merge(int lil,int lip){
    if(find_ac(lil) == find_ac(lip)){
        father[lil] = find_ac(lil);
        father[lip] = father[lil];
        return 1;
    }
    return 0;
}
void init(int lil){
    for(int i = 1 ; i <= lil ; i++){
        father[i] = i;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    return 0;
}
