#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
    int a1,a2;
}a[N];
bool cmp(node x,node y){
    return x.a2<y.a2;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].a1;
        a[i].a2=(int)log2(a[i].a1)*2-a[i].a1;
    }
    sort(a+1,a+n+1,cmp);
    int sum=a[1].a1;
    for(int i=2;i<=m;i++){
        sum=sum&a[i].a1;
    }
    cout<<sum<<'\n';
    return 0;
}
