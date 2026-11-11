#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main( ){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	long long a[100005];
	int len=0;
	bool f=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		len++;
	}
	long long c,d,q;
	cin>>c>>d>>q;
	int x1,x2,y1,y2;
	long long b[100005];
	long long ak[100005];
	long long ak1[100005];
	for(int i=0;i<m;i++){
		cin>>a[i]; 
	} 
	for(int i=0;i<n;i++){
		cin>>b[i]; 
	} 
	for(int i=0;i<n+2;i++){
		cin>>ak[i];
	}
	for(int i=0;i<n+2;i++){
		cin>>ak1[i];
	}
	cin>>x1>>y1;
	cin>>x2>>y2;
	len-=1;
	long long zhi=a[1]-a[0];
	for(int i=0;i<len;i++){
		if(a[i+1]-a[i]!=zhi){
			f=false;
		}
	}
	if(f){
 		long long ans=0;
 		long long s1=a[1]-a[0];
   		for(int i=m;;i++){
   			i-=s1;
 			s1*=2;
       		if(i>0){
   				ans++;
			}
			else{
				break;
			}
		}
		if(ans>len+1){
			cout<<len+1;return 0;
		}
		cout<<ans;return 0;
	}
	long long min=1234567890;
	long long min2=1234567890;
	long long x=-345678900;
	int ans=0;
	for(long long j=m;j>0;j-=min){
		for(long long i=0;i<n;i++){
			if(a[i+1]-a[i]<=min2&&a[i+1]-a[i]>=x){
				min=a[i+1]-a[i];
				min2=a[i+1]-a[i];
			}
		}
		x=min2;
		min2=1234567890;
		if(j>0){
			ans++;
		}
		else{
			cout<<ans;return 0;
		}
	}
	cout<<ans;
	return 0;
} 
