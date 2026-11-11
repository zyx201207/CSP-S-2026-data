#include<bits/stdc++.h>
using namespace std;
long long n,sz,ans,sum;
char zm;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s="";
	for(long long i=1;i<=n;i++){
		cin>>sz>>zm;
		for(long long j=1;j<=sz;j++){
			s+=zm;
		}
		sum+=sz;
	}
	string bs="";
	for(long long i=s.size()-1;i>=0;i--){
		bs+=s[i];
	}
	sum=ceil(sum/2.0);
	for(long long i=0;i<sum;i++){
		if(bs[i]!=s[i])ans++;
	}
	cout<<ans;
	return 0;
}
