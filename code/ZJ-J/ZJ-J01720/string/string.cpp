#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	int n,i,j,a,ans;
	char c;
	cin >> n;
	vector<char> v;
	for(i=0;i<n;i++){
		cin >> a;
		cin >> c;
		for(j=0;j<a;j++){
			v.push_back(c);
		}
	}
	int len = v.size();
	for(i=0;i*2<len;i++){
		if(v[i] != v[len-i-1])ans++;
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
