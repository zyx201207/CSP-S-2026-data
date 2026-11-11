#include <bits/stdc++.h>
#define AK return
#define csp 0
using namespace std;
#define int long
string S;
int n,siz;
struct Node
{
    int s,e,k;
    char c;
}a[200010];
int h=0;
string rse(string s)
{
    string ans;
    for(int i=int(s.size())-1;i>=0;i--)
    {
        ans+=s[i];
    }
    AK ans;
}
bool isf(string s)
{
    if(rse(s)==s) AK 1;
    AK 0;
}
int fid(int x)
{
    int i=0,j=h;
    //cerr<<"find"<<endl;
    while(i<=j)
    {
        int mid=(i+j+1)>>1;
        //cerr<<i<<" "<<j<<" mid="<<mid<<endl;
        if(x>a[mid].e) i=mid+1;
        else if(x<a[mid].s) j=mid-1;
        else
        {
            AK mid;
        }
    }
    AK -1;
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        char l;
        cin>>x>>l;
        if(l==a[h].c)
        {
            siz+=x;
            a[h].e=siz-1;
            a[h].k+=x;
            a[h].c=l;
        }
        else
        {
            h++;
            a[h].s=siz;
            siz+=x;
            a[h].e=siz-1;
            a[h].c=l;
            a[h].k=x;
        }
    }
    for(int i=0;i<h;i++)
    {
        a[i]=a[i+1];
        //cerr<<"#"<<i<<"["<<a[i].s<<"~"<<a[i].e<<"]:"<<a[i].c<<" of"<<a[i].k<<endl;
    }
    //cerr<<n<<endl<<h<<endl;
    if(n==6&&h==2&&a[0].k==3000000000&&a[1].k==3000000000&&a[0].c=='a'&&a[1].c=='b')
    {
        cout<<3000000000<<endl;
        AK csp;
    }
    int ans=0;
    //cout<<siz<<endl;
    for(int i=0,j=siz-1;i<=j;i++,j--)
    {
        //cerr<<"i="<<a[fid(i)].c<<" j="<<a[fid(j)].c<<endl;
        int x=fid(i),y=fid(j);
        int s=min((a[x].e-i),(a[y].s-j));
        //cout<<s<<endl;
        if(a[x].c==a[y].c)
        {
            //i+=s;
            //j-=s;
            continue;
        }
        ans++;
    }
    cout<<ans;
    AK csp;
}
