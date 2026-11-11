#include<bits/stdc++.h>
using namespace std;	
long long a[5000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;	
	long long mb=m;
	long long sum=0;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	sum/=n;
	long long cent;	
	long long centi;
	long long mnc;
	long long num=1;
	mnc=max(a[0],sum);
	mnc-=min(a[0],sum);
	for(long long i=0;i<n;i++){
		long long djc;
		djc=(max(a[i],sum))-(min(a[i],sum));
		if(djc<=mnc){
			cent=a[i];	
			centi=i; 
		}
	}
	for(long long i=centi-1;i>=0;i--){
		if((cent-a[i])<=mb){
			num++;
			mb-=(cent-a[i]);
		}
	}
	cout<<num;
	return 0;
}