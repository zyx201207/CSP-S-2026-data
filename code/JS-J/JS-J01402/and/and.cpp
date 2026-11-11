#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
int n,m;
int v[N],he[40],a[N];
vector<string> s;
string er(int n)
{
    string r="";
    while(n!=0)
    {
        r=char(n%2+'0')+r;
        n/=2;
    }
    return r;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    m=n-m;
    s.push_back("0");
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s.push_back(er(a[i]));
    }
    int len=-1;
    for(int i=1;i<=n;i++)
    {
        int siz=s[i].size();
        len=max(len,siz);
    }
    for(int i=1;i<=n;i++)
    {
        int len1=s[i].size();
        for(int j=1;j<=len-len1;j++)
            s[i]="0"+s[i];
    }
    for(int i=1;i<=len;i++)
        for(int j=1;j<=n;j++)
            he[i]+=s[j][i-1]-'0';
    for(int i=1;i<=len;i++)
    {
        if(m>=n-he[i])
        {
            for(int j=1;j<=n;j++)
            {
                if(s[j][i-1]=='0'&&v[j]==0)
                    v[j]=1,m-=1;
            }
        }
        else
            continue;
    }
    ll ans=-1;
    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            if(ans==-1)
                ans=a[i];
            else
                ans=ans&a[i];
        }
    }
    cout<<ans<<endl;
	return 0;
}

