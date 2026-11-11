#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s="";
	cin>>n;
	while(n--){
        long long a;
        char c;
        cin>>a>>c;
        for(long long i=1;i<=a;i++)
            s+=c;
	}
	long long ans=0;
	for(long long i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-i-1])
            ans++;
	cout<<ans;
	return 0;
}
