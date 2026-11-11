#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long jiechen(int n){
	int in=1;
	for(int i=1;i<=n;i++){
		in*=i;
	}
	return in;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n],b[n],ma=0,mma=0,sm=m,ms=0,s=0,d=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int x=0;x<jiechen(n);x++){
		for(int i=0;i<n;i++){
			sm=m;
			for(int j=i,k=0;j<m;j++,k++){
				if(sm-j<0){
					b[k]+=sm;
				}
				b[k]+=m-j;
				if(k+1>n){
					b[k+1]=sm;
					break;
				}
			}
			ms=0;
			for(int j=0;j<n;j++){
				s=0,d=b[j];
				for(int k=0;k<n;k++){
					if(b[k]==d){
						s+=1;
					}
				}
				
				ms=max(ms,s);
			}
			ma=max(ms,ma);
		}
		mma=max(mma,ma);
	}
	cout<<mma;
	fclose(stdin);fclose(stdout);
	return 0;
}