#include<bits/stdc++.h>
using namespace std;
int aaa[100000000];
int bbb[100000000];
int ccc[100000000];

int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b,c,d,e,n,m,ans=0,l = 0;
	string s,s1;
	cin>>n;
	s="";
	for (int i = 0;i<n;i++){
		cin>>a>>s1;
		for (int j = 0;j<a;j++){
			s+=s1;
		}
		l+=a;
	}
	
	for (int i = 0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			s[l-1-i] = s[i];          
			ans+=1; 
		}
	}
	cout<<ans;
	
	return 0;
} 
