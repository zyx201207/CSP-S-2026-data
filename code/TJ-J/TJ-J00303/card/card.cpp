#include <bits/stdc++.h>
using namespace std;
int a,b;
int x[500020];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>a>>b;
	for (int i=1;i<=a;i++){
		cin>>x[i];
	}
	if(b==1){
		cout<<a;
		return 0;
	}
	
	cout<<a<<b;
	//ceil floor sort sprt pow 
	return 0;
} 
