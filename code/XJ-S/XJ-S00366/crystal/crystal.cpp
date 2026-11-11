#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b,o,i;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		if(a[i]==i){
			o=1;
		}
	}
	if(o==1){
		for(i=1;i<=m;i++){
			b+=i;
		}
	}
	cout<<(b-i-m/5)/2-m/2+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
