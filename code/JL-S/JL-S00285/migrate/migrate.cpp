#include<bits/stdc++.h>
using namespace std;
int a,b,c[1000],l,s,t,q,an,tim,p,pp,v[1000];
int main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
    cin>>p>>pp;
    p=0;
    while(p!=pp){
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>v[i];
        c[i]=v[i];
    }
    for(int i=0;i<a;i++){
        if(c[i]+b>=c[i+1]){
                l=i;
                s=l;
            while(1){
                l++;
        if(l==a)
            break;
            }
        }
    }
        s-=1;
    while(1){
        for(int i=0;i<s;i++){
        q=b*2;
        if(c[i]-c[0]<q){
                        an++;
        tim=i;
        break;
        }
    }
    if(tim>=s)
        break;
    }
    cout<<an;
    p++;
    }
        return 0;
}
