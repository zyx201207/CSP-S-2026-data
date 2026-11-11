#include<bits\stdc++.h>
using namespace std;
long long a[500005];
int sum=0;
long long s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if((s[i]+m)/i>=a[i]){
			sum++;
		}else{
			break;
		}
	}
	cout<<sum;
	return 0; 
} 
