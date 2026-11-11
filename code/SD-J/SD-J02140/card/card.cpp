#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001],sl[300001];
void pd(int x){
	long long pz[n+1-x]={0};
	for(int i=x;i<=n;i++){
		pz[i]=a[i];
		for(int j=x;j<i;j++){
			if(pz[j]==pz[i]){
				for(int k=j;k<=i;k++){
					pz[k]=0;
				}
			}
		}
	}
	for(int i=x;i<=n;i++){
		if(pz[i]!=0){
			sl[pz[i]]+=1;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		pd(i);
	}
	for(int i=1;i<=n;i++){
		cout<<sl[i];
	}
}
