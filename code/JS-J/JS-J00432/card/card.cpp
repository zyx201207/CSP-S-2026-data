#include<bits/stdc++.h>
using namespace std;
int c[500010],d[500010];
long long n,q,m;
int main(){
    freopen("card4.in","r",stdin);
    freopen("card4.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i];
    d[1]=c[1];
    for(int i=1;i<=m;i++)cout<<m<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
