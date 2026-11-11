#include<bits/stdc++.h> 
using namespace std;
int n,m,A;
long long ans,cnt,a[500010],b[500010],c[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			A++;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(int i=n;i>=1;i--){
		c[i]=a[i]+c[i+1];
	}
	if(A==n){
		for(int i=1;i<=n;i++){
			if(m-b[i]<0){
				cout<<i;
				return 0;
			}
		}
	}
	sort(b+1,b+n+1);
	int bq=m;
	for(int i=1;i<=n;i++){
		if(bq-b[i]>=0){
			ans++; 
			bq-=b[i];
		}
		else {
			break;
		}
	}
	bq=m;
	for(int i=1;i<=n;i++){
		if(bq-c[i]>=0){
			cnt++; 
			bq-=c[i];
		}
		else {
			break;
		}
	}
	cout<<max(cnt,ans)+1;
	return 0;
}
