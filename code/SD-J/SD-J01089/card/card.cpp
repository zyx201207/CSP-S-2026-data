#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[500007];
int s[500007];
int t[500007];
int l[500007],r;
int stk[500007];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		s[a[i]]++;
	}
	for (int i=1; i<=n; i++) {
		r=1;
		memset(t,0,sizeof(t));
		for (int j=i; j<=n; j++) {
			if (t[a[j]]!=0&&t[a[j]]<r) {
				//for (int k=t[a[j]]+1;k<=r;k++)t[stk[k]]=0; 
				r=t[a[j]]+1;
			} else {
				t[a[j]]=r;
				stk[++r]=a[j];
			}
		}
		for (int j=1;j<=r;j++){
			l[stk[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<l[i]<<' ';
	}
	return 0;
}
/*
10 3 3 1 2 1 3 2 3 1 2 1
*/
