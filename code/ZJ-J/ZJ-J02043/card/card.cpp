#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+10],w[m+10];
	memset(w,0,sizeof(w));
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		int q[500010],u=0;
		for (int j=i;j<=n;j++){
			bool f=1;
			for (int p=1;p<=u;p++){
				if (q[p]==a[j]){
					u=p;
					f=0;
					break;
				}
			}
			if(f){
				u++;
				q[u]=a[j];
			}
		}
		for (int j=1;j<=u;j++){
			w[q[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout << w[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
