#include<bits/stdc++.h>
#define ll long long
#define u(i,x,y) for(int i=x;i<=y;i++)
#define d(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
const int N=3e6+5;
const ll inf=1e9+7;
ll n;
char c[N];
ll a[N];
ll cc,aa,d,d1,ans=0,ii;
bool b=0;
bool bj[N]={};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    u(i,1,n){
        cin>>a[i]>>c[i];
    }
    ii=1;
    aa=a[1];
    cc=c[1];
    int x=(n-1)/2+1;
    u(i,1,n){
        //cout<<aa<<" "<<char(cc)<<" "<<ans<<endl;
        if(b==1) d=i;
        else d=n-i+1;
        if(cc==c[i] and i!=1 and bj[d]==0 and cc==c[i-1]){
            aa+=a[i];
        }
        if(cc==c[d]){
            if(aa>=a[d]){
                aa-=a[d];
                bj[d]=1;
                b=0;
            }
            else if(aa<a[d]){
                ii=d;
                ll d1=a[d]-aa;
                aa=d1;
                bj[ii]=1;
                b=1;
                b=0;
            }
        }
        if(cc!=c[d] and bj[d]==0){
            if(aa>=a[d]){
                ans+=a[d];
                aa-=a[d];
                c[d]=c[ii];
                bj[d]=1;
            }
            else if(aa<a[d]){
                ans+=aa;
                ii=d;
                ll d1=a[d]-aa;
                aa=d1;
                c[ii]=c[d];
                bj[ii]=1;
                cc=c[d];
                b=1;
            }
        }

    }
    //cout<<aa<<" "<<char(cc)<<endl;
    cout<<ans;
    return 0;
}
