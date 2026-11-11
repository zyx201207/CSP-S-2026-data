#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m;
	cin>>n>>m;
	long long a[50001];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	long long an[50001];
	bool k1=false;
	for(long long i=1;i<n;i++){
		an[i]=a[i]-a[i-1];
		if(a[i]==a[i-1]){
			k1=true;
		}
	}
	
	sort(an+1,an+n);
	long long arr=0;
	long long k=0;
	for(long long i=1;i<=n;i++){
		if(arr+an[i]<=m){
			k++;
			arr+=an[i];
		}else{
			break;
		}
		
	}
	cout<<k;
	return 0;
}
