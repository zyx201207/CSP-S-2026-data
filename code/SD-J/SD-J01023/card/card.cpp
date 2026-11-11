#include<bits/stdc++.h>
using namespace std;

int a[500005];
int js[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int fp=0;
	cin>>a[1];
	int f=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			fp=1;
		}
	}
	if(f==0){
		cout<<n;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				js[i]++;
			}
		}
		for(int i=m;i>=1;i--){
			cout<<js[i]<<" ";
		}
	}
	return 0;
} 
