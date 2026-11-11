#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> v(n+3);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	long long a=v[0];
	if(m==1){
		for(int i=1;i<n;i++){
			a=max(a,v[i]);
		}
		cout<<a;
	}
	else if(m==n){
		for(int i=1;i<n;i++){
			a=a&v[i];
		}
		cout<<a;
	}
	else if(m==2){
		a=0;
		long long j=1;
		for(int i=0;i<n-1;i++){
			a=max(a,v[i]&v[i+1]);
			if(i==n-1){
				i=j;
				j++;
			}
		}
		cout<<a;
	}
	else if(m==n-1){
		long long j=0,ma=0;
		while(j<n){
			if(j!=0) a=v[0];
			else a=v[1];
			for(int i=0;i<=n;i++){
				if(i==j) i++;
				else a=a&v[i];
			}
			ma=max(ma,a);
			j++;
		}
		cout<<ma;
	}
	return 0;
} 
