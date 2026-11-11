//SN-J01034 马星辰 西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++){
		for (int j = i+m-1;j<=n;j++){
			ans=max(ans,a[j]&a[i]);
		}
	} 
	cout<<ans;
	return 0;
}
