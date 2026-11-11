#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000005];
long long ts[100000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ts[i]=a[i];
	}
	long long js=0;
	long long sum1=1;
	long long sum2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			sum2++;
		}	
	}
	if(sum2>0&&m==0){
		cout<<sum2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			sum1++;
		}	
	}
	if(sum1>1&&m==0){
		cout<<sum1;
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(ts[i]-a[1]<=m){
			js+=i;
			break;
		}else{
			continue;
		}
	}
	cout<<js;
	return 0;
}
