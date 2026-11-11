#include<bits/stdc++.h>
using namespace std;
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
const maxn=10000010;
int a[maxn];
int main(){
    int n,m;
    cin>>n' '>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[j];
            cout<<max(a[j],' ',a[j+1]);
        }
    }
    return 0;
}
