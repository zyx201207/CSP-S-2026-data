#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[500001],cnt[300001],f[300001],zz[300001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,cnnt = 0;
	cin >> n >> m;
	bool fl = false;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		if(x == a[cnnt] and fl);
		else if(x == a[cnnt] and !fl)
			fl = true,a[++cnnt] = x;
		else fl = false,a[++cnnt] = x;
	}n = cnnt;
	for(int i = 1;i <= n;i++){
		int k = 1;
		memset(f,0,sizeof f);
		memset(zz,0,sizeof zz);
		for(int p = i;p <= n;p++){
			if(f[a[p]]){
				k = f[a[p]] + 1;
				for(int j = k;j <= n and zz[j] != 0;j++)
					f[zz[j]] = 0;
			}
			else{
				zz[k] = a[p];
				f[a[p]] = k;
				k++;
			}
		}for(int j = 1;j < k;j++)
			cnt[zz[j]]++;
	}for(int i = 1;i <= m;i++)
		cout << cnt[i] << ' ';
	return 0;
}