#include<bits/stdc++.h>
using namespace std;
long long  n,m,a[1000002],s,d=999999,c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	 for(int i=1;i<=n;i++){
	 	s+=a[i];
	 }
	 if(s%n==0)s/=n;
	 else s=s/n+1;	
	for(int i=1;i<=n;i++){if(a[i]==s)c++; 
		if(s-a[i]<=0)d=min((s-a[i])*-1,d);
		else d=min(s-a[i],d);
	 }
	 
	 d=s-d;
	for(int i=1;i<=n;i++){
		if(a[i]<d&&m-d+a[i]>=0){
			m-=d-a[i];
			c++;
		}
	 }cout<<c;
	return 0;
}
