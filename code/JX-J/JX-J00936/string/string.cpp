#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN];
long long ans,pre[MAXN];
char c[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],pre[i]=pre[i-1]+a[i];
    //for(int i=1;i<=n;i++) cout<<"Debug:pre["<<i<<"]="<<pre[i]<<endl;
    int p=1,q=n;
    long long s=1,t=pre[n];
    while(p<q)
    {
        //cout<<"Debug:p="<<p<<",q="<<q<<",s="<<s<<",t="<<t<<endl;
        long long jmp=min(pre[p]-s+1,t-pre[q-1]);
        //cout<<"Debug:jmp="<<jmp<<endl;
        //cout<<"Debug:ans="<<ans<<endl;
        if(c[p]!=c[q]) ans+=jmp;
        //cout<<"Debug:ans'="<<ans<<endl;
        s+=jmp,t-=jmp;
        //cout<<"Debug:s'="<<s<<",t'="<<t<<endl;
        while(p<q&&s>pre[p]) p++;
        while(p<q&&t<pre[q-1]+1) q--;
    }
    cout<<ans;
    return 0;
}
