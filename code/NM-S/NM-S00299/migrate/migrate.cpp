#include<bits/stdc++.h>
using namespace std;
string s,c;
int a,n,res;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s=s+c;
	}
	if(s.size()%2==1){
		int l=(s.size()-1)/2,r=(s.size()-1)/2;
		for(int i=1;i<=(s.size()+1)/2;i++){
			l--;
			r++;
			if(s[l]-'0'!=s[r]-'0') res++;
		}
	}
	if(s.size()%2==0){
		int l=s.size()/2-1,r=s.size()/2;
		for(int i=1;i<=(s.size()/2);i++){
			if(s[l]-'0'!=s[r]-'0') res++;
			l--;
			r++;
		}
	}
	cout<<res;
	return 0;
} 
