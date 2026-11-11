#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,a[100000010];
char c;
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c;
		while(a[i]--){
			s+=c;
		}
	}
	int len=s.size();
	for(int j=len-1;j>=0;j--){
		s2+=s[j];
	}
	for(int i=0;i<=len-1;i++){
		if(s[i]!=s2[i]){
			cnt++;
		}
	}
	cout<<cnt/2;
}