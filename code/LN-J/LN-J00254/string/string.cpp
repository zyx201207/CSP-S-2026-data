#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	while(n--){
		int x;
		cin>>x;
		string c;
		cin>>c;
		while(x--)s+=c;
	}
	
	if(s.size()==1||s.size()==0) {
		cout<<"1";
		return 0;
	}
	string s2;
	long long ans=0;
	long long len=s.size();
	if(len%2==0){
		for(long long i=len/2-1;i>=0;i--){
			s2+=s[i];
			//cout<<s[i];
		}
		int t=1;
		for(long long i=len/2;i<len;i++){
			if(s2[t++]!=s[i]) ans++;
			//cout<<s[i]<<" "<<s2[t];
		}
	}else{
		long long t=1;
		for(long long i=len/2;i>=0;i--)s2+=s[i];
		for(long long i=len/2+1;i<len;i++){
			if(s2[t++]!=s[i]) ans++;
		}
		long long k=ans;
		ans=0,t=1;
		for(long long i=len/2;i>=0;i--){
			s2+=s[i];
		}
		for(long long i=len/2+1;i<len;i++){
			if(s2[t++]!=s[i]) ans++;
		}
		ans=min(k,ans);
	}
	cout<<ans;
	return 0;
}

