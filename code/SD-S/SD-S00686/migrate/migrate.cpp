#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define ull unsigned long long
#define int long long
#define endl '\n'
using namespace std;
int x[2000010];
int l[2000010];
int r[2000010];
int v[2000010];
int ct[2000010];
//multiset<int>s,t;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IO;
	int c,T;
	cin >> c >> T;
	while(T--)
	{
		int ans=0;
//		s.clear();
//		t.clear();
		int n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++)
		{
			cin >> x[i];
			ct[i]=0;
			l[i]=i;
			r[i]=i;
			v[i]=0;
		}
		if(d<=1||n<=3)
		{
			cout << 0 << endl;
			continue;
		}
		int k=1;
		for(int i=2;i<=n;i++)
		{
			if(x[i]-x[k]>d)
			{
				l[i-1]=k;
				r[k]=i-1;
				while(x[i]-x[k]>d)
				{
					k++;
				}
			}
			if(i==n)
			{
				l[n]=k;
				r[k]=n;
			}
		}
		for(int i=2;i<=n;i++)
		{
			r[i]=max(r[i],r[i-1]);
		}
		for(int i=n-1;i>=1;i--)
		{
			l[i]=min(l[i],l[i+1]);
		}
		for(int i=1;i<=n;i++)
		{
			ct[l[i]]++;
//			cout << ct[l[i]] << " " << l[i] << " " << i << endl;
//			cout << l[i] << " " << r[i] << endl;
		}
//		cout << "__________________________\n";
		for(int i=1;i<=n-3;i++)
		{
			if(r[i]-1!=i)
			{
				v[i]=ct[r[i]-1];
//				cout << ct[r[i]-1] << " " << i  << " " << r[i]-1<< endl;
			}
		}
		k=n-4;
		for(int i=n;i>=1;i--)
		{
			ans+=v[i];
//			cout << v[i] << " " << i << endl;
			while(r[k]>=i&&k>=1)
			{
				if(i==k)
				{
					k--;
					continue;
				}
				if(i==r[k])
				{
					v[k]+=v[i];
//					cout << "***" << k << " " << i <<  " " << v[i] << endl;
				}
				k--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

