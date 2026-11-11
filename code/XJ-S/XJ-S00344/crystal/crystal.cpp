#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	float x;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		x+=a[i];
	}x/=n;
	long long x_x=x;
	long long b[n];
	for(long long i=0;i<n;i++){
		b[i]=max(a[i],x_x)-min(a[i],x_x);
	}sort(b,b+n);
	long long ij=0;
	while(m>0){
		m-=b[ij];
		ij++;
	}if(m==0){
		cout<<ij;
	}else{
		cout<<ij-1;
	}
	return 0;
}
