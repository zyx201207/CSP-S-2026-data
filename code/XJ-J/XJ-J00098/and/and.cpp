#include<bits/stdc++.h>
using namespace std;
int n,m;
long long num[200001];
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	sort(num+1,num+n+1);
	long long ans=-114514;
	for(int s=n;s>=n-500&&s>=m;s--){
		long long res=num[s];
		for(int i=s-1;i>=s-m+1;i--)
			res&=num[i];
		ans=max(ans,res);
	}
	cout<<ans;
}
