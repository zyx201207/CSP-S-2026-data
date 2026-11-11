#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n,a[200020];
int k=0,l=0,p=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==4)p++;
		if(a[i]==3)k++;
		if(a[i]==2)l++;
	}
	stable_sort(a+1,a+n+1);
	if(m==1)cout<<a[n];
	else if(m==n){
		k=0x3FFFFFFF;
		for(int i=1;i<=n;i++)k&=a[i];
	}
	else if(a[n]<=4){
		if(m<=p)cout<<4;
		else if(m<=k)cout<<3;
		else if(m<=k+l)cout<<2;
		else cout<<0;
	}
	else cout<<a[n-m+1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
