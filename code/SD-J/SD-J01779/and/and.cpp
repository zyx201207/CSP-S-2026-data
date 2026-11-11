#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans;
	if(m==1){
		for(int i=1;i<=n-1;i++){
			ans=max(a[i],a[i+1]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int a1=a[i]&a[j];
				ans=max(a[i]&a[j],a1);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
