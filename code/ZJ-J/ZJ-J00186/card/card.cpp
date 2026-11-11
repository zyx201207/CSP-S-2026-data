#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010],c[200010],d[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(b[a[i]] != 0){
			c[b[a[i]]] = i;
		}
		b[a[i]] = i;
	}
	for(int j = 1;j <= n;j++){
		for(int i = j;i <= n;){
			if(c[i]!= 0){
				i = c[i];
			}else{
				d[a[i]] ++;
				i++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << d[i] << ' ';
	}
	return 0;
}
