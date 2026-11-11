#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	string s;
	while(n--){
		int a;
		string c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	long long len=s.size();
	for(int i=0,j=len-1;i<=len/2;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
