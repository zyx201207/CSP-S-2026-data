#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long c[10000]={0};
long long x[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>x[i];
	}
	for(int i=0;i<a;i++){
		long long d[10000]={0};
		for(int j=i;j<a;j++){
			d[x[j]]+=1;
			if(d[x[j]]>=2){
				long long d[10000]={0};
			}
		}
		for(int m=1;m<=b;m++){
			if(d[m]==1){
				c[m]+=1;
			}
		}
	}
	for(int i=1;i<=b;i++){
		cout<<b;
		cout<<c[i]<<" ";
	}
	

}
