#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int t[300005],tong[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}for (int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		int pos=0;
		for (int j=1;j<=i;j++){
			if (t[a[j]]==0){
				t[a[j]]++;
				b[++pos]=j;
			}else{
				for (int k=1;k<=pos;k++){
					if (b[k]==a[j]){
						pos=k-1;
						break;
					}
				}b[++pos]=a[j];
			}
		}for (int j=1;j<=pos;j++){
			tong[b[j]]++;
		}
	}for (int i=1;i<=m;i++){
		cout <<tong[i]<<" ";
	}
	return 0;
}
