#include<bits/stdc++.h>
using namespace std;
string s;
int n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	int len=s.size();
	for(int l=0,r=len-1;l<=(len+1)/2,r>=(len+1)/2;l++,r--) if(s[l]!=s[r]) ans++;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
