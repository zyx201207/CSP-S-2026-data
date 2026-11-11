#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],b[5010];
void solve(){
	for(int i = 1;i <= n;i++){
		int d[5010]={},c[5010]={},id=0;
		for(int j = i;j <= n;j++){
			if(c[a[j]]!=0){
				id-=id-c[a[j]];
			}else{
				d[++id]=a[j];
				c[a[j]]=id;
			}
		}for(int j = 1;j <= id;j++){
			b[d[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << b[i] << " ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	solve();
	return 0;
} 
