#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i,j,t=0,s,k;
	int solve=1,x;
	cin>>n>>m;
	long long a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	x=a[1]-a[0];
	for(i=2;i<n;i++){
		if(a[i]-a[i-1]!=x){
		solve=0;
		break;}
	}
	if(solve==1){
		long long q=(m/x)*2,p;
		p=sqrt(q)+1;
		for(i=p;i>0;i--){
			if(i*(i+1)<=q)
			break;
		}
		if(i+1<n)
		cout<<i+1;
		else
		cout<<n;
		return 0;
	}
	for(i=n-1;i>=0&&i+1>t;i--){
		 s=m;
		 k=1;
		 for(j=i-1;j>=0;j--){
		 	if(a[i]-a[j]<=s){
		 		s-=(a[i]-a[j]);
		 		k++;
				if(k>t)
				t=k;
			 }
			else{
				break;
			}
		 }
	}
	cout<<t;
	return 0;
}
