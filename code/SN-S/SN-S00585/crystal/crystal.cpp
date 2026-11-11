#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long maxn=0;
	int a[109100]={};
	cin>>n>>m;  
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long j=1,sum=0,l;
	for(long long i=a[n];i>=a[j];i--){
		sum=0;
		l=m;
		j=m;
		while(l>0&&j>0){	
		if(i==a[j]){
			j--;
			sum++;
		} 
		if(a[j]<i){	
			if(l-(i-a[j])>=0){	
					sum++;
					l=l-(i-a[j]);	
					j--;
				}
				else break;	
			 }
			 else j--;
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	return 0;
}
