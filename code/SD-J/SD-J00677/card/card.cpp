#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1010101];
int cnt[1010101];
vector<int> v;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(n>500){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int now=a[j];
				if(v.size()&&now==v[v.size()-1]){
					v.pop_back();
				}
			//	cout <<"fudguigr\n";
				v.push_back(now);
			}
			for(auto x:v){
				cnt[x]++;
			}
			v.clear();
		}
		for(int i=1;i<=m;i++){
			cout <<cnt[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int now=a[j];
			int pos=-1;
			if(v.size()==0){
				v.push_back(now);
				continue;
			}
			for(int i=0;i<v.size();i++){
				if(v[i]==now){
					pos=i;
					break;
				}
			}
		//	cout <<pos<<"\n";
			if(pos!=-1){
				int q=v.size()-pos;
				while(q--&&v.size()>=1){
					v.pop_back();
				}
				
			}
			v.push_back(now);
//			
		}
		if(!v.size()) continue;
		for(auto x:v){
			cnt[x]++;
		}
		v.clear();
	}
	for(int i=1;i<=m;i++){
		cout <<cnt[i]<<" ";
	}
	return 0;
}
