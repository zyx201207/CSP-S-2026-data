#include<bits/stdc++.h>
using namespace std;
long long n,x,m,c,k;
char a[2000020],y;
int main (){
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	cin>>n;
	while(n--){
		cin>>x>>y;
		m+=x;
		while(x--){
			k++;
			a[k]=y;
		}	
	}
	for(long long i=1;i<=m/2;i++)
		if(a[i]!=a[m-1+1])
			c++;
	cout<<c;
	return 0;
}
