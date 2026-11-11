#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	string S1,S2;
	int n,m,ans;
	char x;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin  >> m >> x;
		for(int j = 1;j<=m;j++){
			S1+=x;
		}
	}
	for(int i = S1.size();i>= S1.size()/2;i--){
		S2+=S1[i-1];
	}
	for(int i = 1;i<= S2.size();i++){
		if(S1[i]!=S2[i]){
			ans++;
		}
	}
	cout << ans-1;
	return 0;
}