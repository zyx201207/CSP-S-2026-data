//西安铁一中滨河高级中学 耿禹墨 SN-S00334 
#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[500005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		int d=0,k=0;
		for(int j=i-1;j>=1;j--){
			k+=a[i]-a[j];
			d++;
			if(k==m) d++;
			if(k>=m) break;
		}
		ans=max(ans,d);
	}
	cout<<ans;
	return 0;
}
