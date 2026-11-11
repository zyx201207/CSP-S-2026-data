#include<bits/stdc++.h>
#define ll long long
#define N 300010
using namespace std;
int n,m,a[500010],f[N];
int st[500010],top=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        top=0;
        memset(st,0,sizeof(st));
        for(int j=i;j<=n;j++)
        {
            for(int k=top;k>=1;k--)
                if(st[k]==a[j])
                    top=k-1;
            st[++top]=a[j];
        }
        for(int j=1;j<=top;j++)
            if(f[st[j]]<i)
                f[st[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<f[i]<<" ";
	return 0;
}
