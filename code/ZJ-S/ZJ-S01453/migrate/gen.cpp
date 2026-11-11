#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

mt19937 rng(random_device{}());
inline int rand(int l,int r){
    return uniform_int_distribution<int>(l,r)(rng);
}

int main(){
    freopen("migrate.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T=1000;
    cout<<0<<' '<<T<<endl;
    while(T--){
        int n,v,d;
        do n=rand(1,100),v=rand(1,300),d=rand(1,v);
        while(v*2+1<n);
        cout<<n<<' '<<d<<endl;
        vector<int> x(n);
        for(int i=0;i<n;i++){
            do x[i]=rand(-v,v);
            while(count(x.begin(),x.begin()+i,x[i]));
        }
        sort(x.begin(),x.end());
        for(int i=0;i<n;i++)cout<<x[i]<<" \n"[i==n-1];
    }
    return 0;
}