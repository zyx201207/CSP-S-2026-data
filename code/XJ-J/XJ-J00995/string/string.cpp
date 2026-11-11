#include<bits/stdc++.h>
using namespace std;
string s,c,s_reverse;
long long n,a,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
			//cout<<s<<'\n';
		}
	}
	long long len=s.size();
	for(int i=0;i<len;i++){
		s_reverse[i]=s[i];
	}
	for(int i=0;i<len;i++){
		if(s_reverse[i]!=s_reverse[len-1-i]){
			s_reverse[len-1-i]=s_reverse[i];
		}
	}
	for(int i=1;i<len;i++){
		if(s[i]!=s_reverse[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}