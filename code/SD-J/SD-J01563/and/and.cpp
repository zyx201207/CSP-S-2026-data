#include<bits/stdc++.h>
using namespace std;
int a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n){
		long long sum=a[1];
		for(int i=2;i<=n;i++)sum&=a[i];
		cout<<sum;
	}else if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(a[i],mx);
		cout<<mx;
	}else if(m==2){
		int mx=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}else{
		sort(a+1,a+1+n,greater<int>());
		long long sum=a[1];
		for(int i=2;i<=m;i++)sum&=a[i];
		cout<<sum;
	}
	return 0;
}
