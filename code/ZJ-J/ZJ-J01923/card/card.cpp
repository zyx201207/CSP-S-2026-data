#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],ans[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		bool t1[300005]= {0},t[300005]= {0};

		for(int j=i; j<=n; j++) {
			if(t[a[j]]==1) {
				for(int k=1; k<=m; k++) {
					t[k]=0;
				}
				//t1[a[j]]=1;
			}
			t[a[j]]++;
		}
		for(int j=1; j<=m; j++) {
			if(t[j]==1)ans[j]++;
		}

	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
10 3
 3 1 2 1 3 2 3 1 2 1

*/
