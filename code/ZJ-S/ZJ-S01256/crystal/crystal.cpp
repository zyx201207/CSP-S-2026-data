#include<bits/stdc++.h>
using namespace std;
long long  n,m,a[5000001],c,d,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	s=a[1];
	c=1;
	for(int i=2;i<=n;i++){
		s+=a[i];
		if(i*a[i]-s>m){
			break;
		}
		else{
			c++;
		}
	}
	cout<<c;
	return 0;
}