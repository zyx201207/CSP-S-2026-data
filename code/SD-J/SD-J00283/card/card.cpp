#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=3e5+10;
int n,m;
int cnt[M],pos[M],a[N],k=1;
void insert(int x){
	if (pos[x]==-1){
			pos[x]=k;
			k++;
		}	
		else{
			int start=pos[x];
			for (int j=1;j<=m;j++){
				if(pos[j]>=start){
					pos[j]=-1;
					k--;
				}
			}
			pos[x]=k;
			k++;
		}
//	for (int i=1;i<=m;i++)	cout << pos[i] << " ";
//	cout << endl;
}
signed main(){
	   freopen("card.in","r",stdin);
	   freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(pos,-1,sizeof(pos));
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
//		cin >> a[i];
		for (int j=i;j<=n;j++)	insert(a[j]);
		for (int j=1;j<=m;j++){
			if (pos[j]!=-1){
				cnt[j]++;
//				cout << j<<" ";
			}	
		}
//		cout << endl;
		memset(pos,-1,sizeof(pos));
	}
//	cout << "jj" << endl;
	for (int i=1;i<=m;i++){
	
		cout << cnt[i] << " ";
//		if (cnt[i]==0)	cout << "kk" << endl;
		}
	return 0;
}

