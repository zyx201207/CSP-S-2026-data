#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],cf[500005];
vector<int>wz[300005];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read(),wz[a[i]].push_back(i);
    for(int i=1;i<=n;i++){
        int maxl=i,maxr=i;
        for(int j=i;j<=n;j++){
            if(wz[a[j]][wz[a[j]].size()-1]<=i)
                continue;
            int x=lower_bound(wz[a[j]].begin(),wz[a[j]].end(),i)-wz[a[j]].begin();
            if(wz[a[j]][x]<maxl||wz[a[j]][x]>=maxr)
                cf[wz[a[j]][x]]--,cf[j]++,maxr=j,maxl=wz[a[j]][x];
        }
    }
    for(int i=1;i<=n;i++)
        cf[i]+=cf[i-1];
    for(int i=1;i<=n;i++)
        cnt[a[i]]+=i+cf[i];
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<' ';
    return 0;
}
