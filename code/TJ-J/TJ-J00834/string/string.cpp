#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,a,cnt=0,op=pow(2,19);
	string b,c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a<=500){
			for(int j=0;j<a;j++){
				c+=b;
			}
		}
		else{
			for(int j=0;j<a/op;j++){
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b;
				c+=b;
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b; 
				c+=b;
				c+=b;
			}
			for(int j=0;j<a%op;j++){
				c+=b;
			}
		}
	}
	long long l=0,r=c.length()-1;
	while(l<=r){
		if(c[l]!=c[r])
			cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
	
}
