#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],len,c[500005],mx=0;
int f(int x){
    for(int i=1;i<=len;i++)
        if(b[i]==x)
            return i;
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }for(int jv=1;jv<=n;jv++){
        memset(b,0,sizeof b);
        len=0;
        for(int i=jv;i<=n;i++){
            int pos=f(a[i]);
            if(pos!=-1){
                for(int j=pos+1;j<=len;j++)b[j]=0;
                len=pos;
            }else{
                len++;
                b[len]=a[i];
            }
        }for(int i=1;i<=len;i++)c[b[i]]++;
    }for(int i=1;i<=mx;i++)cout<<c[i]<<" ";
    return 0;
}
