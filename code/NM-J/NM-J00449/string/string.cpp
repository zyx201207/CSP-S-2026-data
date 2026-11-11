#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],e=0,f,g=0;
	char b[200005];
	string c,d;
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	f=n;
	for(int i=1;i<=n/2;i++){
		if(a[i]==a[f-i+1]&&b[i]==b[f-i+1]){
			g++;
		}else if(a[i]==a[f-i+1]&&b[i]!=b[f-i+1]){
			e+=a[i];
			g++;
		}
	}
		for(int i=1+g;i<=n-g;i++){
			for(int j=1;j<=a[i];j++){
				c+=b[i];
			}
		}
	int x=c.size();
	for(int i=x-1;i>=0;i--){
		d+=c[i];
	}
	for(int i=0;i<x/2;i++){
			if(c[i]!=d[i]){
				e++;
			}
		}
	cout<<e;
	fclose(stdin);
	fclose(stdout);
	return 0;
};
