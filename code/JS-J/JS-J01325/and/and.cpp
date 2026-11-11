#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],maxn=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++)for(int j=i;j<=n;j++)maxn=max(a[i]&a[j],maxn);
    cout<<maxn<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
