#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<long long> x(n);
	long long a=0;
	for(int i=0;i<n;++i)
		cin>>x[i];
	if(m==1){
		long long mx=0;
		for(int i=0;i<n;++i){
			mx=max(x[i],mx);
		}
		cout<<mx;
		return 0;
	}
	else if(m==2){
		long long mx=0;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j)
				mx=max(mx,x[j]&x[i]);
			}
			cout<<mx;
			return 0;
		}
	else if(m==n){
		for(int i=1;i<n;++i)
			a=x[i-1]&x[i];
		a=a&x[n-1];
		cout<<a;
	}
	return 0;
}