#include<bits/stdc++.h>
using namespace std;
int a[200005],maxp,ans1,ans[31][200005];
bool ejz[200005][31];
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
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    if(m==1){
        int maxx=0;
        for(int i=1;i<=n;i++)
            maxx=max(maxx,a[i]);
        cout<<maxx;
        return 0;
    }
    if(m==2){
        int maxx=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                    maxx=max(maxx,a[i]&a[j]);
        cout<<maxx;
        return 0;
    }
    sort(a+1,a+n+1);
    int maxx=a[n];
    for(int i=n-1;i>=n-m+1;i--)
        maxx&=a[i];
    cout<<maxx;
    return 0;
}
