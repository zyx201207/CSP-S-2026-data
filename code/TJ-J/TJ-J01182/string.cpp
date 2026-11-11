#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	string S;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;char s;
		cin>>a>>s;
		for(int i=0;i<a;i++){
			S+=s;
		}
	}

	int ans=0;
	int l=S.size();
	for(int i=0;i<(l/2);i++){
		if(S[i]!=S[l-1-i]){
			S[i-1-i]=S[i];
			ans++;
		}
	}
	cout<<ans;
	fclose;
	return 0;
} 
