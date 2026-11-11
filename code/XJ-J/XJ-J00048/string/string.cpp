#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long int n,h=0,hh=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s=s+c;
			h++;
		}
	}
	long long int r=0,l=h;
	while(1){
		if(l<r){
			break;
		}
		if(s[r]!=s[l]){
			hh++;
		}
		r++;
		l--;
	}
	cout<<hh;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
