#include<bits/stdc++.h>
using namespace std;
long long c[200010];
long long n,q,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i];
    sort(c+1,c+n+1);
    q=c[n];
    m--;
    int a=n-1;
    while(m--){
        q=q&c[a--];
    }
    cout<<q;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
