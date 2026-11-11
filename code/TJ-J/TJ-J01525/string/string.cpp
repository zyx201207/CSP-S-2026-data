#include <bits/stdc++.h> 

using namespace std;
vector <char> v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	int tim;
	char x;
	for(int i=1;i<=n;i++){
		cin>>tim>>x;
		while(tim--){
			v.push_back(x);
		}
	}
	int le=v.size();
	int ans=0;
	for(int i=0;i<v.size()/2;i++){
		if(v[i]!=v[le-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
