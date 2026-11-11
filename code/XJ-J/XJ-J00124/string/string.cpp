#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N];string c[N]; 

int main(){
	//freopen(string.in;',''r';stdin);
	//freopen(string.out;',''w';stdout);
	
	int n,ans=0;cin>>n;
	string s1,s2,tihuan;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		s1+=c[i];
	}
	for(int i=1;i<=n;++i){
		if(s1[i]!=s1[-i]){
			tihuan=s1[i];
			s2+=s1[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
