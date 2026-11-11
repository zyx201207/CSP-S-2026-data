#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,m,h=0,j=0;
	char sum[20001],b,sum2[20001]={0},c[20001];
	cin>>n;
	for(int i=0;i<n;i++){
		a=0;b=0;
		cin>>a>>b;
		m+=a;
		for(;j<m;j++){
			sum[j]=b;
		}
	}
	bool g=true;
	for(int i=0,j=m-1;i<n,j>=0;i++,j--){
		sum2[j]=sum[i];
	}
	for(int i=0,j=m-1;i<n,j>=0;i++,j--){
		if(sum2[i]!=sum2[j]){
			sum2[j]=sum2[i];
			h++;
		}
	}
	cout<<h;
	return 0;
} 
