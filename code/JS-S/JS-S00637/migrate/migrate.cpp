#include<bits/stdc++.h>

#define pcn putchar('\n');
#define pck putchar(' ');
#define int long long

using namespace std;
const int mod=998244353;

void free(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
}

int n,m,c,T,l=1,r=1,ans=1,p=0;
int a[2000010];
int b[2000010];
signed main(){
    //scanf("%d",);
    //printf("%d",);
    free();
    cin>>c>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++) a[i]=b[i]=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            int l=lower_bound(a+1,a+1+n,a[i]+d)-a;
            if(l==i+1&&a[i]+d<a[l+1]) b[l]++;
        }
        for(int i=1;i<=n;i++){
            if(b[i]!=0) b[i]+=b[i-1];
        }
        for(int i=1;i<=n;i++){
            int l=lower_bound(a+1,a+1+n,a[i]-d)-a-1;
            if(a[l]+d>=a[l+2]&&a[l]+d<a[l+3]&&l!=0){
                ans++;
                ans+=b[i];
            }
        }
        cout<<ans;
        pcn;
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
