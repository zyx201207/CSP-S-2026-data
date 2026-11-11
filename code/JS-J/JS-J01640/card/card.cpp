#include<bits/stdc++.h>
using namespace std;
typedef long long l;
l dr(){
    l x=0,f=1;
    char c=getchar();
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
l a[200005],f[200005],v[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    l n,m;
    n=dr();
    m=dr();
    for(l i=1;i<=n;i++){
        a[i]=dr();
    }
    for(l i=1;i<=n;i++){
        vector<l> b;
        b.push_back(-1);
        for(l j=1;j<=m;j++){
            v[j]=0;
        }
        for(l j=i;j<=n;j++){
            l x=a[j];
            if(count(b.begin(),b.end(),x)==0){
                v[x]=0;
                b.push_back(x);
            }
            else{
                l t=b.size();
                for(l p=1;p<=t;p++){
                    if(b[p]==x)b.erase(b.begin()+p,b.end());
                }
                b.push_back(x);
            }
        }
        for(l j=1;j<=m;j++){
            if(count(b.begin(),b.end(),j)==1)f[j]++;
        }
    }
    for(l i=1;i<=m;i++){
        cout<<f[i]<<" ";
    }
    return 0;
}
