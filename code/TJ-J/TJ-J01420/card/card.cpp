#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[300005];
int b[500005];
int tong[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		memset(tong,0,sizeof(tong));
		int l = 1;
		int r = 0;
		for(int j = i;j<=n;j++){
			if(tong[a[j]]==0){
				b[++r] = a[j];
				tong[a[j]]++;
			}
			else{
				int flag = 0;
				for(int k = l;k<=r;k++){
					if(b[k]==a[j]){
						tong[a[j]]--;
						b[k] = 0;
						flag = k;
						break;
					}
				}
				for(int k = flag;k<=r;k++){
					tong[b[k]]--;
					b[k] = 0;
				}
				b[++r] = a[j];
				tong[a[j]]++;	
			}
		}
		memset(tong,0,sizeof(tong));
		for(int j = l;j<=r;j++){
//			cout << b[j] << ' ';
			tong[b[j]] = 1;
		}
		for(int j = l;j<=r;j++){
			t[b[j]] += tong[b[j]];
		}
//		cout << endl;
	}
	for(int i = 1;i<=m;i++){
		cout << t[i] << ' ';
	}
	return 0;
}
