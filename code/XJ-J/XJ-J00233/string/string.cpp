#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int z,t;	
int a[1000000];
string b[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	z=s.length();
	for(int i=0;i<z/2;i++){
			if(s[i]!=s[z-1-i]){
				t++;
			}
	}
	cout<<t;
	return 0;
}
