#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[500001]={0,1,3,6,10};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	while(true){
		b[s]=b[s-1]+s;
		if(m<b[s])
			break;
		s++;
	}
	cout<<s;
	return 0;
} 


