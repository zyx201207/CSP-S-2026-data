#include<bits/stdc++.h>
using namespace std;
string a[20010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,sum=0;
	char y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int j=1;j<=x;j++){
		    a[j]=y;	
		}
	}
	int r=1,l=n;
	while(l-r){
		if(a[r]!=a[l]){
			sum++;
		}
		r++;
		l--;
	}
cout<<sum;
return 0;
}
