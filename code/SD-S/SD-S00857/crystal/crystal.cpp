#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ma=-1;
long long m,A[N],B[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&A[i]);
	} 
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++){
		B[i]=B[i-1]+A[i];	
	}
	for(int i=1;i<=n;i++){
		if(A[i]==A[i+1])continue;
		for(int j=i;j>=1;j--){
			if(A[i]*(i-j+1)-(B[i]-B[j-1])<=m){
				ma=max(ma,i-j+1);
			}else{
				break;
			}
		}
	}
	printf("%d",ma);
	return 0;
} 
