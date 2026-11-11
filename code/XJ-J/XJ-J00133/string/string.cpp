#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int c;
		char a;
		cin>>c>>a;
		cnt+=c;
		for(int i=1;i<=c;i++){
			s+=a;
		}
	}
	//	cout<<s;
	int ans=0;
	for(int i=0;i<cnt;i++){
		if(s[i]!=s[cnt+1-i]){
			ans++;
			
		}
	}
	cout<<(ans+1)/2;
	return 0;
}

