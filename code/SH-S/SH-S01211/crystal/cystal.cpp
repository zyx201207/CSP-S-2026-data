#include<bits/stdc++.h>
using namespace std;//5 5 1 2 4 8 9     3
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;//m¿ÉÄÜÎª0 
	cin>>n>>m;
	
	long long dor[50001]={};
	for(int i=1;i<=n;i++){
		cin>>dor[i];
	}
	if(m==0){ 
		long long tong[50001]={};
		for(int i=1;i<=n;i++){
			tong[dor[i]]++;
		}
		long long maxv=1;
		for(int i=1;i<=n;i++){
			if(maxv<tong[i])maxv=tong[i];
		}
		cout<<maxv;return 0;
		
	}
	sort(dor,dor+n);
	long long ans[50000]={};
	long long m2=m;
	for(int i=1;i<n;i++){
		long long goal=dor[i];
		long long left=i-1;
		while(m>0 && left>=0){
			m=m-goal+dor[left];
			ans[i]++;
			left--;
		}if(m<0) ans[i]--;
		m=m2;
	}
	

	long long maxn=0;
	for(int i=1;i<n;i++){
		if(maxn<ans[i]) maxn=ans[i];
	}
	cout<<maxn+1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
