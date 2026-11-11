#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>=5000){
		long long ans=a[2]-a[1];
		long long k=0;
		while(m>=0){
			k+=ans;
			m-=k;
		}	
		cout<<k/ans;
		return 0;
	}
	int k=0;
	int x=0;
	while(a[k]<=a[n/2+1]){
		k++;
	}
	cout<<k-1;
}
	
