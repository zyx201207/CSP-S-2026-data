#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int M = 300005;
int n,m,a[N];
string ans[N];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){//n¾ÖÓÎÏ· 
		while(!v.empty()){
			v.pop_back();
		}
		for(int j=i;j<=n;j++){
			v.push_back(a[j]);
			for(int x=0;x<v.size()-1;x++){
				if(v[x] == v.back()){
					for(int y=0;y<v.size()-1;y++){
						v.pop_back();
					}
				}
				break;
			}
		}
		for(int j=1;j<v.size();j++){
			ans[i]+=" ,";
			ans[i][ans[i].length()-1]=v[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout << rand()%n;
	}
	return 0;
}
