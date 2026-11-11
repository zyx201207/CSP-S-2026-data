#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int ai,ci,n,i,c;
	cin>>n;
	string a,b;
	for(i=1;i<=n;i++){
		cin>>ai>>ci;
	}
		for(i=ai;i<=0;i++){
		a[i]=a[i]+ci;
	}

	for(i=a.length();i<=0;i--){
		b=b+a[i];
	}
	for(i=0;i<a.length();i++){
		if(a[i]==b[i]){
			c=c+1;
		}
	}
	c=c/2;
	cout<<c;
	return 0;
}