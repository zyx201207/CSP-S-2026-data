#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	long long kkk=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		kkk+=a[i];
	}
	kkk=kkk/n;
	sort(a+1,a+n+1);
	long long minb=1e18,p=0;
	for(int i=1;i<=n;i++){
		if(abs(a[i]-kkk)<=minb){
			minb=abs(a[i]-kkk);
			p=i;
		}
	} 
	for(int i=p;i>=1;i--){
		if(m>=a[p]-a[i]){
			m-=a[p]-a[i];
			a[i]=a[p];
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[p])cnt++; 
	}
	cout<<cnt<<endl;
	return 0;
} 