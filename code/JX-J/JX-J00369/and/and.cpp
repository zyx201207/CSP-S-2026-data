#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx=0;
unsigned int an=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> a[i];
    for(int i=1;i<=n-m-1;++i){
        an=a[i];
        for(int j=i+1;j<=i+m-1;++j){
            an=an&a[j];
        }
        mx=max(mx,int(an));
    }
    cout << mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
