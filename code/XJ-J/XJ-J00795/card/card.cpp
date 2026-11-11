#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],cnt[M],k1,k2;
vector <int> vd,vh;
bool p[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		vh.push_back(a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		memset(p,0,sizeof(p));
		bool f=0;
		int id=0;
		for(int j=k1;j<k1+vd.size();j++){
			if(vd[j]==vh[k2]){
				f=1;
				id=j;
				break;
			}
		}
		if(f){
			int l=vd.size();
			for(int j=id;j<l;j++){
				vh.push_back(vd[j]);
				k1++;
			}
			vd.push_back(vh[k2]);
			k2++;
		}
		else{
			vd.push_back(vh[k2]);
			k2++;
		}
		int ll=vd.size();
		for(int j=k1;j<ll;j++){
			if(!p[vd[j]]){
				p[vd[j]]=1;
				cnt[vd[j]]++;
			}
		}
		for(int j=k1;j<ll;j++){
			vh.push_back(vd[j]);
			k1++;
		}
	}
	for(int i=1;i<=m;i++) cout << cnt[i] << " ";
	return 0;
}