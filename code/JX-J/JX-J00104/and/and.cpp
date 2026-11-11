#include <iostream>
#include <vector>
using namespace std;
long long n,m,a[200005],ans;
vector<int> cur;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cur.push_back(a[i]);
    }
    for(int i=30;i>=0;i--){
        vector<int> tmp;
        for(int v:cur){
            if(v & (1<<i)){
                tmp.push_back(v);
            }
        }
        if(tmp.size()>=m){
            ans|=(1<<i);
            cur=std::move(tmp);
        }
    }
    cout<<ans;
    return 0;
}
