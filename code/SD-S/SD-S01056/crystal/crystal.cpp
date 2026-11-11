 #include<bits/stdc++.h>
 #define int long long
 using namespace std;
 int n,m;
 int a[500010];
 int qz[500010];
 int l,r;
 int ans=0;
 queue<int> que;
 signed main()
 {
 	std::ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		qz[i]=qz[i-1]+a[i];
	}
	l=1;r=0;
	int sizee=0;
 	for(int i=1;i<=n;i++)
 	{
 		while(sizee&&(sizee*a[i]-(qz[r]-qz[l-1]))>m)
 		{
 			l++;
			sizee--;
		}
		ans=max(ans,sizee+1);
		r++;sizee++;
	}
	cout<<ans;
	return 0;
}
