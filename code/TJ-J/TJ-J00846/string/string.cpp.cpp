#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
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
