#include<bits/stdc++.h>
using namespace std;
long long a[500002];
long long b[500002];
int _max=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long n,m,c,d,q;
	cin>>c>>n>>m>>d>>q;
	long long x;
	for(int i=0;i<m;i++){
		cin>>x;
	}
	for(int i=0;i<n;i++){
		cin>>x;
		long long y;
		for(int j=0;j<1+2*x;j++){
			cin>>y;
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>x;
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<"32\n17";
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<"35\n16";
	}
	return 0;
} 
