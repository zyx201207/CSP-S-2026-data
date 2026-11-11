#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> v;
		for(int j=i;j<=n;j++){
			v.push_back(a[j]);
			int s;
			s=v.size();
			for(int x=0;x<s-1;x++){
				if(a[j]==v[x]){
					for(int y=x;y<s-1;y++){
						v[y]==0;
					}
				}
			}
		}
		int w;
		w=v.size();
		for(int j=0;j<w;j++){
			if(v[j]!=0){
				b[v[j]]++;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
