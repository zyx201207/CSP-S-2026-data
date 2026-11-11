#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,f=0;
	string s;
	cin>>n;
	while(n--){
		char a;
		int d;
		cin>>d>>a;
		for(int i=f;i<f+d;i++){
			s[i]=a;
		}
		f+=d;
		
	}
	int c=s.size();
	for(int i=0;i<c;i++){
		if(s[i]!=s[c-i]){
			s[c-i]==s[i];
			ans++;
		}
	}
	cout<<ans;
	
	
	
	
return 0;	
}
