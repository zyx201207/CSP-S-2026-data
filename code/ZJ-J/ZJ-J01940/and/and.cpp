#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];	
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				maxx=max(maxx,a[i]&a[j]);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					maxx=max(maxx,a[i]&a[j]&a[k]);
		}
		cout<<maxx;
		return 0;
	}
	else if(m+1==n){
		bool f=true;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(f){
					sum=a[j];
					f=false;
					continue;	
				}
				sum=sum&a[j];
			}
			f=true;
			maxx=max(maxx,sum);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		long long sum=a[1];
		for(int i=2;i<=n;i++) sum=sum&a[i];
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
