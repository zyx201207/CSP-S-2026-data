#include<bits/stdc++.h>
using namespace std;
long long a[101010],e[31],n,m,M,cnt,f=1,mn=2e31-1;
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		M=max(a[i],M);
	}
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			f=0;
			mn&=a[i];
		}
	}
	if(m==1){
		cout<<M;
		return 0;
	}else if(f){
		cout<<a[1];
		return 0;
	}else if(m==n){
		cout<<mn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int j=0;
		while(a[i]){
			if(a[i]&1) e[j]++;
			j++;
			a[i]/=10;
		}
	}
	for(int i=30;i>=0;i--){
		if(e[i]>=m){
			int sum=1;
			for(int l=1;l<=i;l++) sum*=2;
			cnt+=sum;
		}
	}
	cout<<cnt;
	return 0;
}
