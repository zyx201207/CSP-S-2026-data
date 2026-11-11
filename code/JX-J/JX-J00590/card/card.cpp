#include <bits/stdc++.h>
using namespace std;
map<long long ,long long> a,b;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++){
        long long pd=n-1;
        while (a[pd]!=a[i]||pd<i||pd!=i){
            pd--;
        }
        for (int j=pd;j<n;j++){
            b[a[j]]++;
        }
        pd=0;
        while (a[pd]!=a[i]||pd>i||pd!=i){
            pd++;
        }
        for (int j=0;j<pd;j++){
            b[a[j]]++;
    }
    }
    for (int i=0;i<m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
