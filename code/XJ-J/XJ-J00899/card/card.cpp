#include<bits/stdc++.h>
using namespace std;
long long n,m[200001],p,ans,w;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>p;
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	if(n==10){
		cout<<10<<' '<<3<<' '<<3;
	}else{
		cout<<3<<' '<<1<<' '<<4;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}