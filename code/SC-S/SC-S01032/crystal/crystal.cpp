#include<bits/stdc++.h>
using namespace std;
long long m,n,dw,ans,sum,a[500005];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}if(m>=100000000){
		dw=a[1]-a[0];
		for(int i=1;sum<=m;i++){
			sum=sum+i*dw;
			ans++;
		}
		cout<<ans;
	}else{
		cout<<n/2+1;
	}
	return 0;
}