//李沐阳 SN-J00803 西安交通大学附属中学兴庆校区 初一年级
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],b[200010],maxi=0;
void dfs(int ui,int ut){
	b[ut]=1;
	if(ui==m){
		long long mm=131071;
		for(int i=1;i<=n;i++)if(b[i])mm&=a[i];
		b[ut]=0;
		maxi=max(maxi,mm);
	}
	for(int i=ut+1;i<=n;i++)dfs(ui+1,i);
	b[ut]=0;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n==1){
		for(int i=1;i<=n;i++)maxi=max(maxi,a[i]);
		cout<<maxi;
		return 0;
	}
	if(n==m){
		int mm=a[1];
		for(int i=2;i<=n;i++)mm&=a[i];
		cout<<mm;
		return 0;
	}
	dfs(1,0);
	cout<<maxi;
	return 0;
}
