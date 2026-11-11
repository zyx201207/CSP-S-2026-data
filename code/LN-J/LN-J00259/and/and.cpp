#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,un=1,un2=0;
    cin>>n>>m;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-m;i++){
        for(int j=i;j<i+m;j++){
            un=un&a[j];
        }
        if(un>un2){
            un2=un;
        }
    }
    cout<<un2<<endl;
    return 0;
}
