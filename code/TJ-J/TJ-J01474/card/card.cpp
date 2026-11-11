#include <bits/stdc++.h> 
using namespace std;

int n,m;
int a[500010];
vector<int> s;
long long ans[300010];

bool findd(int x){
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == x) return true;
	}
	return false;
}

bool findi(int x){
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == x) return i;
	}
}

void play(int k){;
	s.clear();
	for(int i = k; i <= n; i++){
		if(findd(a[i])){
			int p = findi(a[i]);
			for(int i = (int)s.size()-1; i >= p; i--) s.pop_back();
		}		
		s.push_back(a[i]);
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int k = 1;
	while(k <= n){
		play(k);
		for(int i = 0; i < (int)s.size(); i++) ans[s[i]]++;
		k++;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
