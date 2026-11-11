#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m; 
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==1){
		int maxx=0;
		for (int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	else if (m==n){
		int num=a[1];
		for (int i=2;i<=n;i++){
			num=num&a[i];
		}
		cout<<num;
		return 0;
	}
	else if (m==2){
		sort (a+1,a+n+1);
		int maxx=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				int sum=a[i];
				sum=sum&a[j];
				maxx=max(maxx,sum);
			}
		} 
		cout<<maxx;
		return 0;
	}
	else{
		bool f=0;
		for (int i=2;i<=n;i++){
			if (a[i]-a[i-1]==1){
				f=1;
			}
			else{
				f=0;
			}
		}
		if (f==1){
			cout<<a[n];
		}
	}
	return 0;
}
