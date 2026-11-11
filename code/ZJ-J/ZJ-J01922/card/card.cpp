#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=5e5+5;
int n,m,a[N];
map<int,int> ma;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int> cd;
		map<int,int> mp;
		for(int j=i;j<=n;j++){
//			cout<<"mp[a["<<j<<"]]:"<<mp[a[j]]<<endl;
			if(mp[a[j]]){
				for(int k=cd.size()-1;k>=0;k--){
					if(cd[k]==a[j]){
						mp[cd[k]]--;
						cd.pop_back();
						break;
					}
					mp[cd[k]]--;
					cd.pop_back();
				}
			}
			mp[a[j]]++;
			cd.push_back(a[j]);
//			for(int i=1;i<=m;i++) cout<<mp[i]<<" ";
//			cout<<endl;
		}
		for(int i=0;i<(int)cd.size();i++){
			ma[cd[i]]++;
//			cout<<cd[i]<<" ";
		}
//		cout<<endl<<endl;
	}
	for(int i=1;i<=m;i++){
		if(i==1) cout<<ma[i];
		else cout<<" "<<ma[i];
	}
	return 0;
}

