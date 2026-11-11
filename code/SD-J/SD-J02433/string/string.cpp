#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=1,q=0,w=0;
	cin>>n;
	int a[20055];
	string b[20055],c[20055];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	} 
	for(int i=1;i<=n;i++){
		q+=a[i]; 
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[m]=b[i];
			m++; 
		}
	}
	for(int i=1;i<=q;i++){
		if(c[i]!=c[q-i]){ 
			w++;
		}
	}
	w/=2;
	cout<<w;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
