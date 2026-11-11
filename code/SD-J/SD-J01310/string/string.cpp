#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,sum=0;
	cin>>n;
	int a[n+1]={};
	char c[n+1]={};
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2==0){
		sum/=2;
	}
	else sum=sum/2;
	cout<<sum;
	return 0;
}
