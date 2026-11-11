#include<bits/stdc++.h>
using namespace std;
long long n,s=0;
struct pi{
    long long l;
    char d;
};
pi a[200005]={};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a[i].l>>a[i].d;
    //cout<<1;
    long long q=1,h=n;
    while(1){
        if(q==h||q>h)break;
        if(a[q].l==0)q++;
        if(a[h].l==0)h--;
        if(a[q].d==a[h].d){
            long long b=min(a[q].l,a[h].l);
            a[q].l-=b;
            a[h].l-=b;
        }
        else{
            long long b=min(a[q].l,a[h].l);
            a[q].l-=b;
            a[h].l-=b;
            s+=b;
        }
        //cout<<2;
    }
    cout<<s;
    return 0;
}
/**/
