#include<bits/stdc++.h>
using namespace std;
struct xxx{
	int zhi,step,ju;
}a[1000005];
bool cmp(xxx x,xxx y){
	if(x.zhi==y.zhi) return x.step<y.step;
	return x.zhi<y.zhi;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].zhi;
		a[i].step=i;
		a[i].ju=a[i-1].ju+a[i].zhi;
	}
	sort(a+1,a+n+1,cmp);
	int ans=-100;
	for(int i=1;i<=n-ans+1;i++){
		for(int j=i;j<=n;j++){
			int l=a[j].zhi*(j-i+1)-a[j].ju+a[i-1].ju;
			if(l<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
