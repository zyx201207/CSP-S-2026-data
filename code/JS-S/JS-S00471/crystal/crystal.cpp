#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int n;long long ans=1;
long long m;
long long a[N],b[N],c[N];

long long max(long long a,long long b){return (a>b?a:b);}

int main(){ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++){
        c[i]=a[i+1]-a[i];
        a[i]=a[i-1]+c[i];
    }//a qian zhui he ; c cha fen
    /*for(int i=1;i<=n-1;i++){
        cout<<c[i]<<' ';
    }
    cout<<'\n';
    for(int i=1;i<=n-1;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';*/
    long long tm=0,cnt=1;
    for(long long i=1,l=0;i<=n-1;i++){
        tm+=c[i]*(i-l);
        if(tm>m){
            ans=max(ans,cnt);
            while(tm>m){
                tm-=a[i]-a[l];
                ++l;
                --cnt;
            }
        }
        ++cnt;
    }
    cout<<max(ans,cnt);
    /*for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
        a[i]=a[i-1]+b[i];
        c[i]=b[i]+a[i];
    }
    //a[i]:sigma(b[1,i])
    //b[i]:processed
    //c[i]:cost[1,i]
    for(int i=1;i<=n;i++){
        ans=max(ans,)
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,ex(i));
    }
    cout<<ans;*/


    /*for(int i=1;i<n;i++){
        c[i]=a[i+1]-a[i];
    }
    for(int i=1;i<n;i++){
        m-=1ll*i*c[i];
        if(m<0){
            cout<<i;
            return 0;
        }
    }
    cout<<n;*/

    /*long long t=0;
    for(int i=n-1;i>=1;i--){
        b[i]=a[n]-a[i];
        c[i]=c[i+1]+b[i];
    }
    //[l,r]=c[l]-c[r+1]-b[r+1]*(r-l+1)
    for(int )*/
    return 0;
}
//zhe tai dian nao hao ka
//xie de wo hao nan shou aaaa'a
//xie dai ma su du > guang biao yi dong su du > si kao su du
/*
6 50
1 9 16 22 23 123
*/
//zhu yi dao 16:37 cai qie chu lai
//qi ma shi mei bao 0 ba
//tbw(yong yua ji bu zhu uid xian sheng) de na shuang yan jing jiu jing kan dao le duo yuan
//zai ci wo yao gan xie wo de jia zhang , lao shi , shu bao , dian nao , shui bei , wai tao , shu bao , kong qi , gan mao , dengddd .
//bu hui gei wo pan ding cheng bao li yu yan ba
