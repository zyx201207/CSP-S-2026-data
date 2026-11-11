#include<bits/stdc++.h>
using namespace std;
int n;int a[1000005];char c[1000005];
string s;
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		for(int j=0;j<a[i];j++){
			s.push_back(c[i]);
		}
	}
	long long l = 0,r = s.size()-1;
	while(l<r){
		if(s[l++]!=s[r--]) cnt++;
	}
	cout << cnt;
	return 0;
}
