#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,s,need=0,l=0,g=1;
	char a[999999],z;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>z;
		l=l+s;
		for(int j=g;j<=g+s;j++){
			a[j]=z;
		}
		g=g+s;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[l-i+1]){
			a[i]=a[l-i+1];
			need++;
		}
	}
	cout<<need;
	return 0;
} 
