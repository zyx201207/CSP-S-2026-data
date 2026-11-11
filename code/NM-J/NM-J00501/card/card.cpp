#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int h[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int> v;
		for(int j=i;j<=n;j++){
			bool f=false;
			int w=0;
			for(int x=1;x<v.size();x++){
				if(v[x]==a[j]){
					f=true;
					w=x;
					break;
				}
			}
			if(!f){
				v.push_back(a[j]);
			}
			else{
				for(w;w<v.size();w++){
					v.pop_back();
				}
				v.push_back(a[j]);
			}
		}
		for(int j=1;j<v.size();j++){
			h[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<h[i];
		if(i!=m) cout<<' ';
	}
	return 0;
}
