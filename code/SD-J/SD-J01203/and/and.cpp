#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum,a[200005],sum2;
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	else if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}else if(m==2){
		sum=a[n];
		sum=sum&a[n-1];
		cout<<sum;
	}else if(m==n-1){
		sum=a[1];
		for(int i=2;i<=n-1;i++){
			sum=sum&a[i];
		}
		sum2=a[2];
		for(int i=3;i<=n;i++){
			sum2=sum2&a[i];
		}
		sum=max(sum,sum2);
		cout<<sum;
	}
	return 0;
}

