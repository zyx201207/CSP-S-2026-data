#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<a[1];
		return 0;
	}
	int q=a[1];
	if(n==m){
		for(int i=2;i<=n;i++)
			q=q&a[i];
		cout<<q;
		return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	int sum=a[1];
	for(int i=2;i<=m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	cout<<"\n";
	return 0;
}
