#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int C,T,n;
ll d,x[N];
int a[N],b[N];
vector<int>c[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;++i)cin>>x[i];
        int p=1;
        for(int i=1;i<=n;++i){
            while(p<n){
                if(x[p+1]-x[i]>d)break;
                ++p;
            }
            a[i]=p;
        }
        // for(int i=1;i<=n;++i)fprintf(stderr,"a(%d)=%d\n",i,a[i]);
        p=n;
        for(int i=n;i>=1;--i){
            while(p>1){
                if(x[i]-x[p-1]>d)break;
                --p;
            }
            b[i]=p;
            c[p].push_back(i);
        }
        // for(int i=1;i<=n;++i)fprintf(stderr,"b(%d)=%d\n",i,b[i]);
        ll ans=0;
        for(int i=1;i<=n;++i){
            if(a[i]-i<2)continue;
            // if(i==4)fprintf(stderr,"siz(c(%d))=%lu\n",a[i]-1,c[a[i]-1].size());
            for(int j:c[a[i]-1]){
                ll num1=1,num2=1;
                int x=i;
                for(int k=i-1;k>=1;--k){
                    if(a[k]!=x)break;
                    ++num1;
                    x=k;
                }
                x=j;
                for(int k=j+1;k<=n;++k){
                    if(b[k]!=x)break;
                    ++num2;
                    x=k;
                }
                ans+=num1*num2;
                // fprintf(stderr,"(%d,%d,%d,%d):%lld*%lld\n",i,a[i]-1,a[i],j,num1,num2);
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;++i)c[i].clear();
    }
    return 0;
}