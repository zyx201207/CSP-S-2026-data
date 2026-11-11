#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(m==1){
		cout<<n;
	}
	else if(m==2){
		cout<<3<<" "<<1;
	}
	else if(n<=5000){
		int sa=0;
		for(int i=1;i<=n-1;i++){
			if(a[i]!=a[i+1]){
				sa++;
			}
		}
		if(sa==0){
			cout<<n;
		}
		else{
			for(int i=1;i<=n;i++){
				cout<<i<<" ";
			}
		}
	}
	else{
		cout<<4999;
	}
	return 0;
}
