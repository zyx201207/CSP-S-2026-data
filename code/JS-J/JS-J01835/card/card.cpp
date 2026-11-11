#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m;
int cnt[N];
vector<int> mp;
vector<int> vev;
int find(int l,int x){
	for(long unsigned int i=l;i<=vev.size();i++){
		if(vev[i]==x)
			return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int t;
		cin >> t;
		mp.push_back(t);
	}
	for(int i=1;i<=n;i++){
		for(int w=1;w<=n;w++) vev.push_back(mp[w-1]);
		for(int nowt=i;nowt<=n;nowt++){
				long unsigned int nown=find(nowt,vev[nowt]);
				if(nown){
					while(vev.size()!=nown) vev.pop_back();
				}
				vev.push_back(vev[nowt]);
		}
		while(vev.size()){
			cnt[vev[vev.size()-1]]++;
			vev.pop_back();
		}
	}
	for(int i=1;i<=m;i++)cout << cnt[i] << ' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
