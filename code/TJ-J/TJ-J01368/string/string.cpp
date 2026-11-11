#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200010];
string ss,dss,s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			ss+=s[i];
			dss+=s[i];
		}
	}
	reverse(dss.begin(),dss.end());
	if(n<=2){
		if(ss==dss){
			cout<<0;
		}else{
			cout<<1;
		}
	}else if(ss==dss){
		cout<<0;
		return 0;
	}else{
		long long l=ss.size();
		for(int i=0;i<l/2;i++){
			if(ss[i]!=ss[l-i-1]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}//2


