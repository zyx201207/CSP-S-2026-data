#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[1000000005]={0},b[100000005]={0};
	//freopen(.in,"w",stdin);
	//freopen(.out,"r,",stdout);
	int n,m,maxn=-1,c=0;
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=-1;
	}
	for(int k=1;k<=n;k++){
		b[k]==a[k];
		if(b[k]==a[m]){
			c++;
		}
		bool f=1;
		for (int j=k-1;j>=1;j--){
			if(b[j]==b[k]){
				f=0;
				break;
			}
		}
		if(f==0){
			for (int j=k;j>=1;j--){
			b[j]=-1;
			}
		}
		
	}
	cout<<c;
	return 0;
} 




























































