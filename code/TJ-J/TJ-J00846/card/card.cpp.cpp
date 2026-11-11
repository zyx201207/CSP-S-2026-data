#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("cardl.out","w",stdout);
	int m,n,s,i;
	cin>>n>>m>>i;
	for(int i;i<=0;i++) 
	{
		i=n*n+m;
		m++;
		
	}
	if(s>n){
		cout<<n<<i;
	}
	else{
		cout<<m<<s;
	}
	return 0;
}
