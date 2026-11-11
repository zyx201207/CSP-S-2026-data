#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,ans=0;
	string s,s1;
	cin>>a;
	vector<int> b(a),b1(a);
	vector<char> c(a),c1(a);
	for(int i=0;i<a;i++){
		cin>>b[i]>>c[i];
		b1[a-1-i]=b[i];
		c1[a-1-i]=c[i];
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b[i];j++)s.push_back(c[i]);
		for(int j=0;j<b1[i];j++)s1.push_back(c1[i]);
	}
	for(int i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s1[i])ans++;
	}
	cout<<ans;
	return 0;
}

