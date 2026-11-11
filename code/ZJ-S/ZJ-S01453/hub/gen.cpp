#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

mt19937 rng(random_device{}());
inline int rand(int l,int r){
    return uniform_int_distribution<int>(l,r)(rng);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    vector<int> ns;
    ns.push_back(1000);
    ns.push_back(1000);
    ns.push_back(1000);
    cout<<0<<' '<<ns.size()<<endl;
    for(int n:ns){
        cout<<n<<' '<<2<<endl;
        for(int i=2;i<=n;i++){
            cout<<i-1<<' '<<i<<endl;
        }
    }
    return 0;
}