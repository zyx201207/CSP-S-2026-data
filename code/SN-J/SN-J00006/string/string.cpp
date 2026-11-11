#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	string q,s;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> m >> q;
		for(int j=1;j<=m;j++){
			s +=q;
		}
	}
	string t;
	for(int i=s.size()-1;i>=0;i--){
		t += s[i];
	}
	int sum=0;
	string f;
	int k = s.size()/2;
	for(int i=0;i<=k;i++){
		f+=s[i];
	}
	for(int i=k-1;i>=0;i--){
		f+=s[i];
	}
	for(int i=0;i<s.size();i++){
		if(f[i]!=t[i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
