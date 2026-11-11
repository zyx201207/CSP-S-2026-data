#include <bits/stdc++.h>
using namespace std;
int a[40],b[40],k=0;
int solve(int n){
	if(n==1){
		a[k]=n;
		return 0;
	} else{
		a[k]=n%2;
		k++;
		solve(n/2);	
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,c,m;
	cin>>c>>m;
	int kk=0;
	for(int i=1;i<=c;i++){
		cin>>n;
		solve(n);
		for(int i=0;i<=k;i++){
			b[i]+=a[i];
		}
		kk=max(kk,k);
		k=0;
	}
	int flag=0;
	for(int i=kk;i>=0;i--){
		if(b[i]>=m && flag<m){
			b[i]=1;
			flag++;
		}else{
			b[i]=0;
		}
	}
	long long ans=0;
	for(int i=0;i<=kk;i++){
		ans=ans+b[i]*pow(2,i);
	}
	cout<<ans;
	return 0;
}
