#include<bits/stdc++.h>
using namespace std;
int vis[500005],sj[500005],mans[500005];
int a[500005],s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	int g = 1;
	for (int i = g;i <= n;i++){
		for (int j = 1;j <= m;j++){
			vis[j] = 0;
			sj[j] = 0;
			s[j] = 0;
		}
		int p = i;
		for (int j = i;j <= n;j++){
			s[p] = a[j];
			vis[s[j]]++;
			if (vis[s[j]] > 1){
				for (int k = sj[s[j]];k < j;k++)
					s[j] = 0;	
				vis[s[j]] = 1;
				p = sj[s[j]];
				s[p] = a[j];
			}
			sj[s[j]] = j;
			p++;
		} 
		g++;
		for (int j = 1;j <= m;j++)
			mans[s[j]]++;
	}
	for (int i = 1;i <= m;i++){
		cout << mans[i] << " ";
	}
}