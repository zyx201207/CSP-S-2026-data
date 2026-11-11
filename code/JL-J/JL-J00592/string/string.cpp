#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	char b[200005];
	string s="";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	int h=s.size();
	int k=h;
	for(int i=0;2*i<=h;i++){
		if(s[i]==s[h-i])k--;
	}
	cout<<k;
	return 0;
}
