#include<bits/stdc++.h>
using namespace std;
int n,a[200010],cnt;
char c[200010];
int sum[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	int mid=sum[n]/2;
	for(int i=0;i<mid;i++){
		int x=i,y=sum[n]+1-i;
		
		int l=0,r=n;
		while(l<r){
			int m=(l+r)/2;
			if(sum[m]>=x) r=m;
			else l=m+1;
		}
		char numx=c[l];
		
		l=0,r=n;
		while(l<r){
			int m=(l+r)/2;
			if(sum[m]>=y) r=m;
			else l=m+1;
		}
		char numy=c[l];
		
		if(numx!=numy) cnt++;	
	}
	cout<<cnt;
	return 0;
}