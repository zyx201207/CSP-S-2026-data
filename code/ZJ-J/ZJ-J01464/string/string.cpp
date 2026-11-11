#include<bits/stdc++.h>
using namespace std;
pair<long long,char> p[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].first>>p[i].second;
		len+=p[i].first;
	}
	if(len<1e8){
		long long ans=0;
		string s=" ";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=p[i].first;j++){
				s+=p[i].second;
			}
		}
		for(int i=1;i<=len/2;i++)ans+=(s[i]!=s[len-i+1]);
		cout<<ans;
	}else{
		cout<<len/2;
	}
}
