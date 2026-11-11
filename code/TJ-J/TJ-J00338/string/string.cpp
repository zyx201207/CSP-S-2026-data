#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;string s; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;char b;
		cin>>a>>b;
		while(a--)s+=b;
	}for(int i=0;i<(s.size()+1)/2;i++){
		//cout<<s[i]<<' '<<s[n-i-1]<<endl; 
		if(s[i]!=s[s.size()-i-1])m++;
	}cout<<m;
	return 0;
}

//¿É¶ñ£¬Ã»¸´Ï°×Ö·û´®£¡£¨¿ÞÁ³£© 
//·ÅÆú 
