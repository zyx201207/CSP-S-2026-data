#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char x[200005];
	int t[200005];
	for(int i=0;i<n;i++){
		cin>>t[i];
		cin>>x[i];
	}
	int cnt=0;
	for(int i=0,j=0;i<s.length();i++,j+=t[cnt]){
		for(int j=0;j<t[cnt];j++){
			s[i]=x[i];
		}
		cnt++;
	}
	
	
	int ans=0;
	for(int i=0,j=s.length()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	for(int i=0;i<s.length();i++){
		cout<<s[i];
	}
	
	cout<<ans;
	
	
	
	
	return 0;
}
