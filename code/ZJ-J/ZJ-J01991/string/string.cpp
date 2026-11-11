#include<bits/stdc++.h>
using namespace std;
long long a[1110000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	char s1;
	int n;
	
	cin>>n;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=i;j++){
		cin>>a[i];
		cin>>s;
		} 
	}
	for(int i=1;i<=n;i++){
		s1=a[i]*s1+a[i+1]*s1;
	}
	string l,r;
	int c=0;
	while(l!=r){
		for(int i=1;i<=s.size()-1;i++){
			if(l==r){
			c++;
			 }
		   }
	    }cout<<c;
	return 0;
}