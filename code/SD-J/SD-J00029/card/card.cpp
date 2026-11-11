#include<bits/stdc++.h>
using namespace std;

int a[5006];
int b[3006];
unordered_map<int,int> mp;
int cnt[3006];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		mp.clear();
		for(int j = i;j <= n;j++){
			if(!mp.count(j)){
				mp[a[j]] = j;
			}else{
				for(int k = mp[a[j]];k <= j;k++){
					mp.erase(a[k]);
				}
				mp[a[j]] = j;
			}
		}
		for(int j = 1;j <= m;j++){
			if(mp.count(j)){
				cnt[j]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<cnt[i]<<' ';
	}
	
	return 0;
}

