#include<bits/stdc++.h>
using namespace std;
string a,b;
string k[2005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long f;
		cin>>f;
		string s="",ss="";
		int t=0;
		while(f){
			s+=char(f%2+'0');
			f=f/2;
			t++;
		}
		for(int j=t-1;t>=0;t--){
			ss+=s[j];
		}
		k[i]=ss;
	}
	sort(k,k+n);
	if(m==1){
		cout<<k[n];
	}
	return 0;
}
