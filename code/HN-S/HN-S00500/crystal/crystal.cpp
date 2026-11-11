#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000005],rel=0,re=0;
int main(){
	cin.tie(0);cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n);
	for(long long i=1;i<n;i++){
		long long maxx=1;
		rel=m;
		for(long long j=i-1;j>=0;j--){
			long long fre=a[i]-a[j];
			if(rel-fre>=0){
				rel-=fre;
				maxx++;
			}
			else break;
		}
		re=max(re,maxx);
	}
	cout<<re;
	return 0;
} 
