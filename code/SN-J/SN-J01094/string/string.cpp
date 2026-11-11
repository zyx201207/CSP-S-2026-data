//ps:±©Á¦
#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	vector<char> s;
	s.push_back(' ');
	int len=0;
	for(int i=1;i<=n;i++){
		int l;
		char a;
		cin>>l>>a;
		for(int j=1;j<=l;j++){
			s.push_back(a);
			len++;
		}
	}
	int ans=0;
	for(int i=1; i<=len/2; i++){
		if(s[i]!=s[len-i+1]){
			ans++;
		}
		
	}
	cout<<ans;
	
}

