#include<bits/stdc++.h>
using namespace std;
int n;
//int a;
//char c;
const int MAXN=2e5+5;
long long a[MAXN];
char c[MAXN];
//vector<pair<int ,char>> v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
//		cin>>a>>c;
//		v.push_back({a,c});
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	long long i=0,j=n-1;
	while(i!=j)
	{
//		if(v[i].first>v[j].first)
//		{
////			if(v[i].second!=v[j].second)
////			{
////				ans+=v[j].first;
////			}
////			v[i].first-=v[j].first;
//			j--;
//		}
//		else if(v[i].first<v[j].first)
//		{
////			if(v[i].second!=v[j].second)
////			{
////				ans+=v[i].first;
////			}
////			v[j].first-=v[i].first;
//			i++;
//		}
//		else if(v[i].first==v[j].first)
//		{
////			if(v[i].second!=v[j].second)
////			{
////				ans+=v[j].first;
////			}
//			j--;
//			i++;
//		}
		if(a[i]>a[j])
		{
			if(c[i]!=c[j])
			{
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
		}
		else if(a[i]<a[j])
		{
			if(c[i]!=c[j])
			{
				ans+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
		else if(a[i]==a[j])
		{
			if(c[i]!=c[j])
			{
				ans+=a[j];
			}
			j--;
			i++;
		}
		if(i==j)	break;
	}
	cout<<ans;
	return 0;
}
