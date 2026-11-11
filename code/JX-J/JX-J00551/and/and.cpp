#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a1=INT_MAX,a2=INT_MAX,s[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=m;i++) a1=a1&s[i];
    for(int i=2;i<=m+1;i++) a2=a2&s[i];
    cout<<max(a1,a2);

    return 0;
}
