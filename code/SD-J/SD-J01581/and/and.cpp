#include <bits/stdc++.h>
using namespace std;
int n,m,a[20005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1) for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	else if(m==2){
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
	}
	cout<<ans;
	return 0;
}
