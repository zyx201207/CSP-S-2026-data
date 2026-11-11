#include <bits/stdc++.h>
using namespace std;
int a[500010];
int ai[500010];
int mx=0;
int k=0;
int n,m;
void tui(){
	if (k==n){
		int num=0;
		for (int j=1;j<=n;j++){
			for (int i=1;i<=n;i++){
				if (ai[j]==a[i]){
					num++;
				}
			}
		}
		if (mx<num){
			mx=num;
		}
		return ;
	}
	k++;
	for (int i=1;i<=n;i++){
		ai[i]=a[i]++;
		tui();
	}
}
int main (){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	tui();
	cout<<mx;
	return 0;
}
