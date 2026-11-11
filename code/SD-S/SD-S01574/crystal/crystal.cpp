#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,v1=0,ans=0,v2=0,c;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)v1=1;
		if(a[i]-a[i-1]!=c){
			v2++;
			c=a[i]-a[i-1];
			
		}
	}
	if(v1==0){
		long long q=1;
		while((m-q)>0){
			m-=q;
			ans++;
			q++;
		}
		if(ans!=0)cout<<ans+1;
		else cout<<0;
		return 0;
	}
	if(v2<=2){
		long long q=c;
		while((m-q)>=0){
			m-=q;
			ans++;
			q+=c;
		}
		if(ans!=0)cout<<ans+1;
		else cout<<0;
		return 0;
	}
	long long qf=0,q1,min=99999;
	for(long long k=2;k<=n;k++){
		for(long long i=1;i<=k;i++){
			qf+=a[k]-a[i];
		}
		if(min>qf){
			min=qf;
			q1=k;
		}
	}
	long long i=q1-1;
	while((m-(a[q1]-a[i]))>=0&&i>=-1){
		m-=(a[q1]-a[i]);
		ans++;
		i--;
	}
	if(ans!=0)cout<<ans+1;
	else cout<<0;
	return 0;
} 
