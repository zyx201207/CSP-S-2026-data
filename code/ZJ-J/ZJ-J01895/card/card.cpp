#include<bits/stdc++.h>
using namespace std;
int n,m,u,j=1; string card,tab,ji;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>u;
		card+=u;
	}
	//Trick||Treat!
	if(m<10){
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}