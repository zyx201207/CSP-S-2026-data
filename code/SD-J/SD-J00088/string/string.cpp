#include<bits/stdc++.h>
using namespace std;
long long a[2000005],ans,n;
long long len,cnt,minn=0x3f3f3f3f3f3f3f;
char c[2000005];
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		minn=min(a[i],minn);
	}
	for(long long i=1;i<=n;i++){
		for(int j=(a[i]-minn+1);j>=1;j--) s+=c[i];
	}
	for(long long i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	for(long long i=0;i<s.size();i++){
		if(s1[i]!=s[i]){
			cnt+=minn;	
		}
	}
	cout<<cnt/2;
}
