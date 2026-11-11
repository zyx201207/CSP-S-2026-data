#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
vector<int> a[N],tmp;
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	tmp.resize(n+1);
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>tmp[i];
		if(tmp[i]<tmp[i-1])
			flag=0;
	}
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			int x=tmp[k];
			if(x!=0){
				int pos=-1;
				if(!a[i].empty()){
					if(flag){
						pos=lower_bound(a[i].begin(),a[i].end(),x)-a[i].begin();
						if(a[i][pos]!=x) pos=-1;
					}else{
						for(int j=0;j<a[i].size();j++)
						if(x==a[i][j]){
							pos=j;
							break;
						}
					}
				}
				if(pos!=-1)
					while(a[i].size()>pos)
						a[i].pop_back();
				a[i].push_back(x);
			}
		}
		for(auto x:a[i]) cnt[x]++;
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}//36
