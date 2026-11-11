#include<bits/stdc++.h>
using namespace std;
int n;
int sum[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n; 
	if(n==1){
		cout<<0;
		return 0;
	}
	int a,j;
	string c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum[i]=a+sum[i-1];
	}
	if(sum[n]%2==0){
		j=sum[n]/2;
	}else{
		j=(sum[n]-1)/2;
	}
	cout<<j;
	return 0;
}
