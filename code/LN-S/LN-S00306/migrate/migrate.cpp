#include <bits/stdc++.h>
using namespace std;
int c,T,n,b[2000005];
long long jump[2000005];
long long d,x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> d >> x[1] >> x[2];
        int cntd=0,cnt_jump=0,cha=x[2]-x[1],fla=1;
        if(x[2]-x[1]>d){
            b[++cntd]=2;
            jump[1]=2;
        }
        for(int i=3;i<=n;i++){
            cin >> x[i];
            if(x[i]-x[i-1]>d){
                b[++cntd]=i;
                jump[i-1]=i;
            }
            if(fla==1){
                if(cha!=x[i]-x[i-1]){
                    fla=0;
                }
            }
        }
        if(fla==1){
            if(x[1]+d>=x[3]) cout << 0 << "\n";
            else cout << n-(d/cha)-1 << "\n";
            continue;
        }
        if(cntd==n-1){
            cout << 0 << "\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            int fl=0;
            jump[i]=i;
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]>d) break;
                else{
                    fl=1;
                    jump[i]=j;
                }
            }
            cnt_jump+=fl;
        }
        if(cnt_jump==0){
            cout << 0 << "\n";
            continue;
        }
        int l=1,lc=0,r=1,rc=0,w=1,fl=0,jm=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(i==b[w]){
                w++;
                if(lc && rc){
                    ans+=1ll*(r-l+1)*(rc-lc);
                }
                l=i,r=0,lc=0,rc=0,fl=0,jm=0;
            }
            if(i>=r && r!=0){
                l=i,r=0,fl=0,jm=0;
            }
            if(jump[i]>i+1){
                if(fl==0){
                    fl=i-l+1;
                    r=jump[i];
                    jm=jump[i]-i;
                }
                else{
                    if(jump[i]-i!=jm){
                        ans+=fl;
                        jm=jump[i]-i;
                        fl=i-r+1;
                        r=jump[i];
                        l=r;
                    }
                }
            }
            else if(fl!=0) ans+=fl;
        }
        cout << ans << "\n";
        for(int i=1;i<=n;i++){
            x[i]=0;
            jump[i]=0;
        }
        for(int i=1;i<=cntd;i++) b[cntd]=0;
    }
    return 0;
}