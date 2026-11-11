#include<bits/stdc++.h>
using namespace std;
const int N=510;
int a[N];
vector<int> zz;
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k:zz){
				if(k==a[j]){
					while(1){
						int tt=zz.size();
						if(zz[tt-1]==k){
							break;
						}
						zz.pop_back();
					}
					zz.pop_back();
				}
			}
			zz.push_back(a[j]);
		}
		for(int p:zz){
			cnt[p]++;
		}
		zz.clear();
	}
	for(int i=1;i<=m;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
