#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long,long long>
using namespace std;
long long read(){
    long long k=0;
    int f=1,c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){k=k*10+(c^48);c=getchar();}
    return k*f;
}
void write(long long x){
    if(x<0)putchar('-');
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t,c;
    cin>>c;
    cin>>t;
    while(t--){
        ll n,d;
        n=read();d=read();
        vector<ll>a;
        for(int i=1;i<=n;i++){
            ll x;
            x=read();
            a.push_back(x);
        }
        if(c==11||c==12||c==0){
            ll dif=abs(a[1]-a[0]);
            if(dif>d)write(0);
            else{
                ll y=d/dif;
                if(y==0)y=n;
                else if(y==1)y=n;
                else if(y>=n)y=n;
                else{
                    y=y*2-1;
                }
                //cout<<y<<" ";
                write(n-y);
            }
            putchar('\n');
        }
    }
    return 0;
}
