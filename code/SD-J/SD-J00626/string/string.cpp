#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,x;
	char c;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> x >> c;
		s.insert(s.size(),x,c);
	}
	long long m, t, sum=0;
	if (s.size()%2==0){
		m=s.size()/2;
		t=m-1;
	}else{
		m=s.size()/2+1;
		t=m-2;
	}
	for (int j=m; j<s.size(); j++){
		if (s[j]!=s[t]){
			sum++;
		}
		t--;
	}
	cout << sum;
	return 0;
}
