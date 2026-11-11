#include<bits/stdc++.h>
using namespace std;
bool cf = false;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[100010];
	int as[100010];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int f[1010];
		int r[100010];
		int mx[100010];
		for(int j = i;j <= n;j++){
			r[j] = a[j];
			mx[j] = a[j];
			sort(mx+1,mx+i+1,cmp);
			int p[100010]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			for(int k = i;k < n;k++){
				p[r[k]]+=1;
			}
			int num = 1;
			for(int k = i;k <= n;k++){
				if(p[k] >= 2){
					f[num] = k;
					cf = true;
					num++;
				}
			}
			if(cf){
				for(int v = 1;v <= num;v++){
					int ct = 0;
					for(int k = i;k <= n;k++){
						if(r[k] == f[v] && ct == 0){
							ct++;
							r[k] = 0;
						}
						else if(r[k] != f[v] && ct == 1){
							r[k] = 0;
						}
					}
				}
			}
		}
		int y[100010];
		for(int i = 1;i <= n;i++){
			if(r[i] > 0){
				if(y[i] == 0){
					as[r[i]]++;
					y[r[i]]++;
				}
			}
		}
		cf = false;
	}
	for(int i = 1;i <= m;i++){
		cout << as[i] << " ";
	}
	return 0;
}
