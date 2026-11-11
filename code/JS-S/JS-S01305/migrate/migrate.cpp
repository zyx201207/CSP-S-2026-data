#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,d;
int x[2000006];
int p[2000006];
int r[2000006];
int ans;
void pd(int k){
    int l=k;
    sizeof(p,0,sizeof(p));
    sizeof(r,0,sizeof(r));
    p[k]=1;
    for(int i=k+1;i<=n;i++){
        while(l!=i&&x[i]-x[l]>d) l++;
        if(l==i) break;
        int h=l;
        p[i]=p[l];
        r[i]=r[l]+1;
        while(h+1!=i&&r[h]==r[h+1]){
            h++;
            p[i]+=p[h];
            if(p[i]>2) break;
        }
        if(p[i]==2) ans++;
    }return;
}signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
             cin>>x[i];
        }ans=0;
        for(int i=1;i<=n;i++) pd(i);
        cout<<ans<<"\n";
    }return 0;
}
