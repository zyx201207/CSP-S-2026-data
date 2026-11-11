#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000010];
int cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1])cnt++;
	}	
	if(cnt==n-1){
		cout<<a[1];
		return 0;
	}
	else cout<<"0";
	return 0;
} 
