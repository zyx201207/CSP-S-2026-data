#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],s,x=1;
char c[1979999999],z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>z;
		for(int j=x;j<=a[i]+x;j++){
			c[j]=z;
		}
		x+=a[i];
	}
	for(int i=x/2;i<=x;i++){
		if(c[i]!=c[x+1-i]){
			s++;
		}
	}
	/*
	for(int i=1;i<=x;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	*/
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
