#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;i++){
		if((ans/a[i]!=0&&a[i]/ans!=0)||m+1>n){
			ans&=a[i];
		}
		else{
			if(m+1<=n){
				m++;
			}
		}
	}
	cout<<ans;
	return 0;
}
