#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	string s2;
	for(int i=s.size()-1;i>=0;i--){
		s2+=s[i];
	}
	for(int i=0;i<(s.size()/2+1);i++){
		if(s2[i]!=s[i])sum++;
	}
	cout<<sum;
	return 0;
}
