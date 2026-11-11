#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[m+1],b=0,c[5];
	for(long long i=0;i<n;i++){
		cin>>a[i];
		c[a[i]]++;
		if(a[i]>b) b=a[i];
	}if(m==1) cout<<b;
	else{
		if(c[4]>=m) cout<<4;
		else if(c[3]>=m) cout<<3;
		else if(c[3]+c[2]>=m) cout<<2;
		else cout<<1;
	}
	 
	return 0;
}








//

