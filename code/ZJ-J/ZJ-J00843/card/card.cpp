#include<bits/stdc++.h>
using namespace std;
const int N = 5001;
int a[N];
int ans[N];
int zm[N];
bool bj[3001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		cout << n;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		int xb = 0;
		memset(bj,0,sizeof(bj));
		for(int j = i;j<=n;j++){
			zm[++xb] = a[j];
			if(bj[zm[xb]]){
				bool cf = 1;
				int nxb = xb;
				for(int k = 1;k<xb;k++){
					if(cf){
						if(zm[k]==zm[xb]){
							cf = 0;
							nxb = k;
						}
					}else{
						zm[k]=0;
						bj[zm[k]]=0;
					}
				}
				zm[xb]=0;
				xb = nxb;
				bj[a[j]]=1;
			}else{
				bj[zm[xb]] = 1;
			}
//			for(int k = 1;k<=xb;k++){
//				cout << zm[k] << " ";
//			}
//			cout << "\n";
		}
		for(int j = 1;j<=xb;j++){
			ans[zm[j]]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}