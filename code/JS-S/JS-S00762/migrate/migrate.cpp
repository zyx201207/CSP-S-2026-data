#include <bits/stdc++.h>
using namespace std;
void solve1(){
    int n;
    long long d;
    cin>>n>>d;
    vector<long long> a;
    for (int i=0;i<n;i++){
        long long b;
        cin>>b;
        a.push_back(b);
    }
    if (n==1){
        cout<<0<<endl;
        return;
    }
    long long c=a[1]-a[0];
    d/=c;
    if (d<=1){
        cout<<0<<endl;
        return;
    }
    cout<<max(0ll,n-2*d+1)<<endl;
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if (c==11 || c==12){
        for (int i=0;i<t;i++){
            solve1();
        }
    }
    return 0;
}
