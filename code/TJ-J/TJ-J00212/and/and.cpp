#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
void dfs(long long pos,long long ad,long long cnt,long long c,vector<long long>&x){
	if (cnt>=m){
		ans=max(ans,ad);
//		for (int i = 1;i <= m;i++)cout <<x[i]<<' ';
//		cout <<' '<<ad<<endl;
		return;
	}
	for (int i = pos;i <= n;i++){
		if (cnt==0)ad=a[i];
		else ad &= a[i];
		cout <<a[i]<<' ';
		x.push_back(a[i]);
		dfs(i+1,ad,cnt+1,a[i],x);
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	long long p = 1;
	vector<long long>x;
	for (int i = 1;i <= 32;i++)p*=2;
	p-=1;


	if (n >= 20){
		for (int i = 1;i <= n;i++){
			ans=max(ans,a[i]);
		}
		cout <<ans;
		return 0;
	}
	if (m==n){
		ans=p;
		for (int i = 1;i <= n;i++){
			ans&=a[i];
		}
		cout <<ans<<endl;
		return 0;
	}
	if (n<=20||m <1)
	return 0;
}
