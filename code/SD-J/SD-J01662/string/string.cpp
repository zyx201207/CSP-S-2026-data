#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	int n,a,l=-1,x=0;
	char c;
	string b="";
	cin>>n;
	for(int i=1;i<=n;i++){  cin>>a>>c; l+=a;  for(int i=1;i<=a;i++) {b+=c;} }
	for(int i=0;i*2<l;i++){ if(b[i]!=b[n-1-i]) {x++;} }					
	cout<<x;	
		
		
	
		
		
	
		
	
		




	return 0;
}
