#include <bits/stdc++.h> 
using namespace std;
int n,a,b,s;
char c[1000],d[1000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>b; 
		for (int i=1;i<=a;i++){
			c[i]=b;
		}
	}    
	if (n==1){
		cout<<0;
	}	
	for (int i=c.size();i<=1;i--){
		d[i]=c[i];
	}
	for (int i=c.size();i<=1;i--){
		if (d[i]==c[i]){
			cout<<0;
		}
	}
	if (c.size()%2!=0){
	    cout<<2;
		} 
		}
	return 0;
}
