#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(s[a[i]])s[a[i]]+=i;
        else s[a[i]]=1;
    }
    for(int i=1;i<=m;i++)cout<<s[i]<<' ';
    return 0;
}
