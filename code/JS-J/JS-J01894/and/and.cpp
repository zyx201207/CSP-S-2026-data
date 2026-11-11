#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005];
int c[200005];
int maxn,ans,ansss;
void f(int d,int k,int x,bool o)
{
    if(d>n)
    {
        if(k==0) ansss=max(ansss,x);
        return ;
    }
    f(d+1,k,x,o);
    if(k>0&&o==0) f(d+1,k-1,a[d],1);
    if(k>0&&o) f(d+1,k-1,(x&a[d]),o);
    return ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(a[i],maxn);
        ans=(ans&a[i]);
        if(i==1) b[i]=a[i];
        else b[i]=(b[i-1]&a[i]);
    }
    c[n]=a[n];
    for(int i=n-1;i>=1;i--)
    {
        c[i]=(c[i+1]&a[i]);
    }
    if(n<=20)
    {
        f(1,m,0,0);
        cout<<ansss<<endl;
        return 0;
    }
    if(m==1)
    {
        cout<<maxn<<endl;
        return 0;
    }
    if(m==n)
    {
        cout<<ans<<endl;
        return 0;
    }
    if(m==2)
    {
        int anss=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int x=(a[i]&a[j]);
                anss=max(anss,x);
            }
        }
        cout<<anss<<endl;
        return 0;
    }
    if(m==n-1)
    {
        int anss=0;
        for(int i=2;i<n;i++)
        {
            anss=max(anss,(b[i-1]&c[i+1]));
        }
        cout<<max(anss,max(b[n-1],c[2]))<<endl;
        return 0;
    }
    if(maxn<4)
    {
        int gs1=0,gs2=0,gs3=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1) gs1++;
            if(a[i]==2) gs2++;
            if(a[i]==3) gs3++;
        }
        if(gs3>=m) cout<<"3"<<endl;
        else
        {
            if(gs3+gs2>=m) cout<<"2"<<endl;
            else
            {
                if(gs3+gs2+gs1>=m) cout<<"1"<<endl;
                else cout<<"0"<<endl;
            }
        }
        return 0;
    }
    cout<<maxn<<endl;
    return 0;
}
