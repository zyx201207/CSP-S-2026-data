#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t1=0,t=0,a;
	cin>>n;
	char c[1000001],c1;
	for(int i=0;i<n;i++){
	cin>>a>>c1;
	for(int j=0;j<a;j++){
		c[t1]=c1;
		t1++;
	}
	}
	for(int i=0;i<=n;i++){
		if(c[i]!=c[n/2]){
			t++;
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
	             