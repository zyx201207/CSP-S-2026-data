#include<bits/stdc++.h>
using namespace std;
int n,ma,j;
long long m,co,op;
long long a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	
	scanf("%d%d",&n,&m);
	ma=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		a[i]=a[i+1]-a[i];

	}
	
	co=0;op=0;j=n-2;
	for(int i=n-1;i>=0;i--){		
		while (j>=0){
			op=op+a[j];
			co=co+op;
			if(co>m) break;
			j--;
		}
		
		if(i-j>ma) {
			ma=i-j;
			if(j==0) break;
		}
		
		op=op-a[i-1];
		co=co-a[i-1]*(i-j);
		j--;
	}
	
	printf("%d",ma);
	
	return 0;
} 
