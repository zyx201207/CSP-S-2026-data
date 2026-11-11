#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char n[10000];
	long long a,t,c=1,g=0;
	char z;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>t>>z;
		for(int j=1;j<=t;j++){
			n[c]=z;
			c++;
		}
	}
	for(int i=1;i<=c;i++){
		if(i==c){
			break;
		}
		if(n[i]!=n[c]){
			g+=1;
		}
		c--;
	}
	cout<<g;
	return 0;
}