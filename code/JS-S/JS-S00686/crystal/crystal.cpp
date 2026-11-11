#include <bits/stdc++.h>
using namespace std;
long long n,a[500010],m,c[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long i,j,s=-2147483647,u,v;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        u=0;
        v=0;
        for(j=i-1;j>=1;j--){
            if(a[i]-a[j]+v>m){
                break;
            }
            u=u+1;
            v=v+a[i]-a[j];
        }
        s=max(u+1,s);
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
