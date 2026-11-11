#include<bits/stdc++.h>
using namespace std;
long long m;
long long n;
vector<long long> a(n+10,1e12+1);
vector<long long> b(n+10);
long long sum=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a.begin(),a.end());

	for(long long i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	for(long long i=0;i<n-1;i++){
		if(m<b[i]*sum){
			break;
		}
		if(a[i]!=a[i+1]){
			m-=b[i]*sum;
			sum++;
		}else{
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
