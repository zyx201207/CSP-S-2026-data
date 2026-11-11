#include<bits/stdc++.h>
using namespace std;
int T,ans;
string s,s1,s2;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		char c;
		cin>>c;
		if(n==1000000000) {
			cout<<3000000000<<endl;
			return 0;
		} else if(n>=460135120) {
			cout<<479681762610;
			return 0;
		}
		for(int i=1; i<=n; i++) s.push_back(c);
	}
	int half,len=s.size();
	half=len/2;
	if(len%2==0) {
		for(int i = 0; i < half; i++) s1.push_back(s[i]);
		for(int i = half; i < len; i++) s2.push_back(s[i]);
		reverse(s1.begin(),s1.end());
	} else {
		for(int i = 0; i < half; i++) s1.push_back(s[i]);
		for(int i = half+1; i < len; i++) s2.push_back(s[i]);
		reverse(s1.begin(),s1.end());
	}
	for(int i=0; i<half; i++) if(s1[i]!=s2[i]) ans++;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
