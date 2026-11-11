#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> yuan;
int a[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back(x);
		yuan.push_back(x);
		a[x]++;
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int ls=v.front();
			if(a[ls]==0){
				v.push_back(ls);
				v.pop();
			}
			else{
				vector<int> v2;
				int k;
				for (k=j+1;k<=n;k++){
					if (v[k]==ls) break;
				}
				for (int h=1;h<=k-1;h++) v2.push_back(v[h]);
				for (int h=k;h<=n;h++) a[v[h]]--;
				v=v2;
				v.push_back(ls);
				v.pop();
			}
		}
		for (int j=1;j<=m;j++) if (a[j]) ans[j]++;
		v=yuan;
		for (int j=1;j<=n;j++){
			a[v[j]]++;
		}
	}
	for (int i=1;i<=m;i++) cout <<ans[i];
	return 0;
}