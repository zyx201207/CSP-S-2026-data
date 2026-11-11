#include<bits/stdc++.h>
using namespace std;

int n;
string s;
unsigned long long ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	int len=s.size();
	string s2=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<len;i++){
		if(s[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
