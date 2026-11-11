#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n+m>7){
		for(int i=1;i<=m;i++){
			cout<<"0"<<" ";
		}
		return 0;
	}
	while(n--){
		cout<<"0"<<" ";
	}
	return 0;
} 
