#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
const int M=25000005;
int c,t,n,d,x[N],dis[N],num[N],ans;
bool unok[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    for(int h=1;h<=t;++h){
        if(c<=10){
            cin>>n>>d;
            for(int i=1;i<=n;++i){
                cin>>x[i];
            }
            ans=0;
            for(int i=1;i<n;++i){
                for(int j=i;j<=n;++j){
                    dis[j]=num[j]=unok[j]=0;
                }
                int head=i;//the earliest one k can reach
                num[i]=1;
                for(int k=i+1;k<=n;++k){
                    while(x[k]-x[head]>d) ++head;
                    dis[k]=dis[head]+1;
                    for(int l=head;dis[l]==dis[head];++l){
                        if(unok[l]) {unok[k]=1;break;}
                        num[k]+=num[l];
                        if(num[k]>2) {unok[k]=1;break;}
                    }
                    if(num[k]==2) ++ans;
                }
            }
            cout<<ans<<endl;
        }
        if(c==11||c==12){
            cin>>n>>d;
            for(int i=1;i<=n;++i){
                cin>>x[i];
            }
            d/=(x[2]-x[1]);
            if(d==0||d==1) cout<<0<<endl;
            else if(n>=2*d) cout<<(n-2*d+1)<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
