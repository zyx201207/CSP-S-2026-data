#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			continue;
		}
		int w=m;
		int cnt=1;
		for(int j=i-1;j>=1;j--){
			if(w>=(a[i]-a[j])){
				w-=a[i]-a[j];
				cnt++;
			}
			else{
				break;
			}
		}
		int s=ans;
		ans=max(ans,cnt);
		if(ans==s){
			break;
		}
	}
	cout<<ans;
	return 0;
}