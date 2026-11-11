#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int plus=0;
	for(int i=n;i>1;i--){
		int nw=1;
		int x=m;
		if(a[i]==a[i+1]){
			continue;
		}
		for(int j=i-1;j>=1;j--){
			if(x-(a[i]-a[j])>=0){
				nw++;
				x=x-(a[i]-a[j]);
			}
			else{
				if(plus!=0) continue;
				else break;
			}
		}
		ans=max(ans,nw);
	}
	cout<<ans;
	return 0;
} 
