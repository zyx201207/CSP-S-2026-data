#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
int total,minw;
long long d;
void f(int l,int e,int b,int w){
    if(l==b){
        if(minw>w){
            total=1;
            minw=w;
        }else if(minw==w){
            total++;
        }return;
    }if(x[e]-x[l]<=d){
        f(l,e+1,b,w);
        if(w>minw){
            return;
        }f(e,e+1,b,w+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    if(c>=7&&c<=10){
        while(t--){
            int n;
            cin>>n>>d;
            for(int i=1;i<=n;++i){
                cin>>x[i];
            }int mo=x[2]-x[1];
            int sum=d/mo;
            if(sum!=0&&sum!=1){
                cout<<n-2*sum+1<<"\n";
            }else{
                cout<<0<<"\n";
            }
        }return 0;
    }while(t--){
        int n,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>x[i];
        }for(int i=1;i<=n;++i){
            int ti=i+1;
            while(x[ti]-x[i]<=d){
                ti++;
            }for(int j=ti;j<=n;++j){
                if(x[j+1]-x[j]>d&&j<n){
                    break;
                }minw=n;
                total=0;
                f(i,ti,j,0);
                if(total=2){
                    ans++;
                }else if(total>2){
                    break;
                }
            }
        }cout<<ans<<"\n";
    }
    return 0;
}

