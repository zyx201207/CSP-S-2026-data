#include <bits/stdc++.h>
using namespace std;
int n;
struct H{
	long long si;
	char ai;
}a[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long s;
		char c;
		cin>>s>>c;
		a[i].si=s;
		a[i].ai=c;
	}
	long long sum=0;
	int l=0,r=n-1,x=0,y=0;
	while(l<r){
		if(a[l].ai!=a[r].ai)
			sum+=min(a[l].si,a[r].si);
		long long p=min(a[l].si,a[r].si);
		a[l].si-=p;
		a[r].si-=p;
	//	cout<<l<<" "<<r<<" "<<sum<<" "<<a[l].si<<" "<<a[r].si<<" "<<min(a[l].si,a[r].si)<<'\n';
		if(0==a[l].si){
			l++;
		}
		if(0==a[r].si){
			r--;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4
6 a
7 b
4 c
2 a
*/
