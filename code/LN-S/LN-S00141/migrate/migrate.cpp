#include<bits/stdc++.h>
using namespace std;
long long c,T,n,m,a[2000010],t[2000010];
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    if(c==13||c==14) {
        while(T--) {
            cin>>n>>m;
            int jl=0;
            long long ans=0;
            for(int i=1;i<=n;i++) {
                cin>>a[i];
                if(a[i]-a[1]<=m) {
                    jl=i;
                }
            }
            int x=1;
            while(x<=jl) {
                if(a[n]-a[x]<=m) {
                    break;
                }
                int f=0,g=0;
                for(int i=jl;i<=n;i++) {
                    if(a[i]-a[x]<=m) {
                        f=i;
                    }
                    else {
                        break;
                    }
                }
                for(int i=f+1;i<=n;i++) {
                    for(int j=i-1;j>=x;j--) {
                        if(a[i]-a[j]<=m) {
                            g=j;
                        }
                        else {
                            break;
                        }
                    }
                    if(f-g==1&&a[i]-a[x]>m) {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    else {
        while(T--) {
            cin>>n>>m;
            long long ans=0,jl=1;
            for(int i=1;i<=n;i++) {
                cin>>a[i];
            }
            int i=2;
            while(i<=n) {
                while(a[i]-a[i-1]<=m&&i<=n) {
                    jl++;
                    i++;
                }
                if(jl%m==0) {
                    ans=ans+jl/m-1;
                }
                else {
                    ans=ans+jl/m;
                }
                jl=0;
            }
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
