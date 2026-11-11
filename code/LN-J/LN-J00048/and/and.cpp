#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x1,int x2){return x1>x2;}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	int ans=a[0];
	if(m==1){cout<<a[0];return 0;}
	if(m==2)
	{
		ans&=a[1];
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;return 0;
	}
	bool f4=0;
	for(int i=0;i<n;i++) if(a[i]>=4){f4=1;break;}
	if(f4==0)
	{
		int a4[4]={0,0,0,0};
		for(int i=0;i<n;i++)
		{
			a4[a[i]]++;
		}
		if(a4[3]>=m)	cout<<"3";
		else if(a4[3]+a4[2]>=m)	cout<<"2";
		else if(a4[3]+a4[1]>=m) cout<<"1";
		else cout<<"0";
		return 0;
	}
	for(int i=1;i<m;i++) ans&=a[i];
	cout<<ans;
	return 0;
}
