#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	int a;
	string l;
	int sum = -1;
	int ans =0;
	for(int i=1;i<=n;i++){
		cin >> a;
		cin >> l;
		sum += a;
		for(int j=1;j<=a;j++) s += l;
	}
	for(int i=0;i<=sum/2;i++){
		if(s[i] != s[sum-i]){
			s[sum-i] = s[i];
			ans++;
		}
	}
	cout << ans <<endl;
	return 0;
}
