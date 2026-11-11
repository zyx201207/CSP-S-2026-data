#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[200009];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		long long cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==2){
		long long maxn=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long y=a[i]&a[j];
				if(y>maxn){
					maxn=y;
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	long long sum=a[1];
	for(int i=2;i<=m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	
	
	
	
	return 0;
}
