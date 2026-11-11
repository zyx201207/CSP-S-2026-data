#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5*2+10;
int a[MAX];
int maxn=INT_MIN;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        maxn=max(maxn,a);
    }
    cout<<maxn;
    return 0;
}
