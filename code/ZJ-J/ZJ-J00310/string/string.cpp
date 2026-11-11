#include <bits/stdc++.h>
using namespace std;
long long a[100005],n,len;
char s[100005];
string st;
long long h(string s1){
	string s2;
	long long ans=0;
	for(int i=len-1;i>=0;i--){
		s2+=s1[i];
	}
	for(int i=0;i<=len/2+1;i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	if(len%2==0){
		if(s1[len/2+1]!=s2[len/2+1]){
			ans--;
		}
	}
	return ans;
}
int main(){
	//freopen("string2.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		int x=a[i];
		while(x--){
			st+=s[i];
		}
	}
	len=st.size();
	cout<<h(st);
	return 0;
}
