//Oct31==Dec25? 关于今天是圣诞节这件事 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,A=1;
int a[500005],diff[500005],sum[500005],ans=-1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	diff[1]=0;
	for(int i=2;i<=n;i++)diff[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		int now=0,p=1;
		for(int j=i+1;j<=n;j++){
			now+=(max(diff[i],diff[j])-min(diff[i],diff[j]))*p;
			p++;
			if(now<=m)ans=max(ans,j-i+1);
			else break;
		}
	}
	cout<<ans;
}
//完了，我背的全是图论，但今年没有 
