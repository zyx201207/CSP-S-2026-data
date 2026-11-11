#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
void df(int i){
	bool c=false;
	int p=0;
	for(int j=n;j>i;j--){
		if(a[i]==a[j]){
			p=j;
			c=true;
			break;
		}
	}
	if(c==false){
		for(int k=i;k<=n;k++){
			b[a[k]]++;
		}
		return;
	}
	df(p);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		df(i);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
