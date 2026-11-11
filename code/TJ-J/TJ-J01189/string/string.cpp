#include<bits/stdc++.h>
using namespace std;

int n,x;
char a;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s1+=a;
		}
	}
	int f=0;
	for(int i=0;i<s1.size();i++){
		if(s2[i]==s1[i]){
			f=0;
			break;
		}
		else f=1;
	}
	if(f==1)cout<<0;
	else cout<<s1.size()/2;
	
	return 0;
}
