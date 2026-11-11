#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr first
#define sc second
#define pii pair<int,int>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define ro(i,r,l) for(int i=r;i>=l;i--)
const int N=2e6+5;
int Caseid,T,n,d,a[N],f[N],g[N];
namespace BIT{
    #define lb (x&-x)
    int mn[N],c[N];
    void add(int x,int f,int g){
        for (;x;x-=lb){
            if (f<mn[x])
                mn[x]=f,c[x]=g;
            else if (f==mn[x])
                c[x]+=g;
        }
    }
    pii query(int x){
        int f=1e18,g=1;
        for (;x<=n;x+=lb){
            if (mn[x]<f)
                f=mn[x],g=c[x];
            else if (mn[x]==f)
                g+=c[x];
        }
        return {f,g};
    }
}
using namespace BIT;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>Caseid>>T;
    if (Caseid<=10){
        while (T--){
            cin>>n>>d;
            fo(i,1,n)
                cin>>a[i];
            int rs=0;
            fo(i,1,n){
                f[i]=0,g[i]=1;
                fo(j,1,n)
                    mn[j]=1e18,c[j]=1;
                add(i,0,1);
                fo(j,i+1,n){
                    int t=lower_bound(a+1,a+n+1,a[j]-d)-a;
                    pii rt=query(t);
                    f[j]=rt.fr+1,g[j]=rt.sc;
                    add(j,f[j],g[j]);
                    if (f[j]<1e18&&g[j]==2)
                        rs++;
                }
            }
            cout<<rs<<'\n';
        }
        return 0;
    }
    if (Caseid<=12){
        while (T--){
            cin>>n>>d;
            int delta;
            fo(i,1,n)
                cin>>a[i];
            if (n==1){
                cout<<"0\n";
                continue;
            }
            delta=a[2]-a[1];
            delta=d/delta;
            if (delta<=1||delta>n/2){
                cout<<"0\n";
                continue;
            }
            cout<<n-delta*2+1<<'\n';
        }
        return 0;
    }
    if (Caseid<=14){
        while (T--){
            cin>>n>>d;
            fo(i,1,n)
                cin>>a[i];
            int id=0;
            fo(i,1,n)
                if (a[i]-a[1]<=d&&a[n]-a[i]<=d){
                    id=i;
                    break;
                }
            if (id==1||id==n){
                cout<<"0\n";
                continue;
            }
            int rs=0;
            fo(i,1,id-1)
                if (a[id+1]-a[i]<=d&&(id+2>n||a[id+2]-a[i]>d)){
                    int t=lower_bound(a+1,a+n+1,a[id-1]+d+1)-a;
                    rs+=n-t+1;
                }
            fo(i,id+1,n)
                if (a[i]-a[id-1]<=d&&(id-2<1||a[i]-a[id-2]>d)){
                    int t=lower_bound(a+1,a+n+1,a[id+1]-d)-a-1;
                    rs+=t;
                }
            cout<<rs<<'\n';
        }
        return 0;
    }
    return 0;
}