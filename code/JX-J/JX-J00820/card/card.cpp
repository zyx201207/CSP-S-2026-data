#include <bits/stdc++.h>
using namespace std;
long long n,m,p,t,s[300005];
vector<long long> a,b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> p;
		a.push_back(p);
	}
	for (int i = 1;i <= n;i++){
		for (int t = i-1;t <= n-1;t++){
		for (int j =0;j < int(b.size());j++){
			if (b.empty()){
				break;
			}else if (b[j]==a[t]){
				b.erase(b.begin()+j,b.end());
				//cout << a[t] << " ";
				break;
			}
		}
	
		b.push_back(a[t]);
		//cout << a[t] << " ";
	}
		for (auto j : b){
			s[j]++;
			//cout << j << " ";
		}
		//cout << endl;
		//for (auto j : b){
			//cout << j << " ";
		//}
		//cout << endl;
		b.erase(b.begin(),b.end());
	}
	for (int i = 1;i <= m;i++){
		cout << s[i] << " ";
	}
	return 0;
}
