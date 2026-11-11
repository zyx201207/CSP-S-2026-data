#include<bits/stdc++.h>
using namespace std;
int n,a[2000005],t1,t2,ans;
char c[2000005];
map<int,char>s1,s2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(n==2)
    {
        cout<<min(a[1],a[2]);
        return 0;
    }
    for(int i=1;i<=n/2;i++)
        if(a[i]==a[n-i]&&c[i]!=c[n-i])
            ans+=a[i];
    cout<<ans;
	return 0;
}
