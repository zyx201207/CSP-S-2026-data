#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=a[1];
	int _max=0;
	for(int i=2;i<=n;i++){
		while(i<=m&&m<=n){
			ans=ans&a[i];
			i++;
		}
		m++;
		if(ans!=_max){
			_max=max(ans,_max);
		}
		ans=a[i];
	}
	cout<<_max;
	return 0;
}
