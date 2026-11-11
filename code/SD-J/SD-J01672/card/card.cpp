#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000000],b[10000000],c[100000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	int x1;
	for(int i = 1;i<=n;i++){
		int x = 0;
		memset(b,0,x1+2);
		for(int j = i;j<=n;j++){
			for(int s = j;s>=1;s--){
				if(a[j] == b[s]&&a[j]!=0&&b[s]!=0){
					for(int w = s;w<=x;w++){
						a[w] = 0;
					}
					x = s-1;
					break;
				} 
			}
			x++;
			b[x] = a[j];
		}
		for(int i = 1;i<=x;i++){
			if(b[i]!=0){
				c[b[i]]++; 
			}
		}

		x1 = x;
	}
	for(int i = 1;i<=m;i++){
		cout << a[i] << " ";
	}
	return 0;
}
