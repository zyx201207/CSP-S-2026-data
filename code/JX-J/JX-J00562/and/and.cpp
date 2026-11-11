#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
struct q{
    vector<ll>p;
}a[35];
map<ll,ll>o;
ll n,m,v,c,b[N],q=0,s,d,f,z,x;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=31;i++){
        s+=pow(2,i);
    }
    d=s;
    z=s;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        x=max(b[i],x);
        z=z&b[i];
    }
    if(m==1){
        cout<<x<<endl;
        return 0;
    }
    if(m==n){
        cout<<z<<endl;
        return 0;
    }
    for(int i=0;i<=30;i++){
        for(int j=1;j<=n;j++){
            if((b[j]>>i)&1==1){
              //  cout<<b[j]<<" "<<i<<endl;
                a[i].p.push_back(b[j]);
            }
        }
    }
    for(int i=30;i>=0;i--){
        if(a[i].p.size()>=m){
            v=i;
            break;
        }
    }
    f=s;
    ll t=f;
    f=0;
    for(int j=v;j>=0;j--){
        for(int i=0;i<a[v].p.size();i++){
            if((a[v].p[i]>>j)&1==1){
                ++c;
                o[i]=1;
            }
        }
        if(c==m){
                c=0;
            for(int i=0;i<a[v].p.size();i++){
                if(o[i]){
                    s=s&a[v].p[i];
                }
            }
            break;
        }
        else{
            for(int i=0;i<a[v].p.size();i++){
                if(o[i]){
                    t=t&a[v].p[i];
                    o[i]=0;
                }
            }
            f=max(t,f);
        }
    }
    if(s==d){
        cout<<f<<endl;
        return 0;
    }
 //   cout<<v<<endl;
    cout<<s<<endl;
	return 0;
}
