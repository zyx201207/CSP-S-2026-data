#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long len=0,sum=0,n=0;
	vector<long long> a(100010,0);
	vector<long long> b(100010,0); 
	cin>>n;
	int m=1;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x;
		cin>>y;
		int s=y-'a'+1;
		if(s==a[m-1]){
			b[m]+=x;
		}else{
			m++;
			b[m]+=x;
			a[m]=s;
		}
	}
	long long r=1,l=m,c=0,sum2=0;
	while(l!=r){
		int lc=min(b[r],b[l]);
		if(a[r]!=a[l]){
			sum+=lc;
			b[r]-=lc;
			b[l]-=lc;
		}else{
			b[r]-=lc;
			b[l]-=lc;
		}
		if(b[r]==0){
			if(r==l)break;
			r++;
		}
		if(b[l]==0){
			if(r==l)break;
			l--;
		}
	}
	cout<<sum;
	return 0;
} 
