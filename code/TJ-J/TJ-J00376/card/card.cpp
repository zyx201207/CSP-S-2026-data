#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
const int M=3*1e5+10;
int n,m;
int a[N],see[M],front[M],ans[M];

void work (){
	for (int i=n;i>=1;i--){
		if (!ans[a[i]]) ans[a[i]]=i;
	}
	for (int i=1;i<=m;i++) cout << ans[i] << ' ';
	return;
}

int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	int wone=0;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]<a[i-1]) wone=1;
	}
	if (!wone){
		work();
		return 0;
	}
	int i=1;
	while (i<=n){
		for (int j=1;j<=m;j++){
			front[j]=0;
			see[j]=0;
		}
		for (int j=i;j<=n;j++){
			if (!front[a[j]]){
				front[a[j]]=j;
				see[a[j]]=1;
			}
			else{
				for (int k=front[a[j]]+1;k<j;k++){
					front[a[k]]=0;
					see[a[k]]=0;
				}
				front[a[j]]=j;
			}
		}
		for (int j=1;j<=m;j++){
			ans[j]+=see[j];
		}
		i++;
	}
	for (int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0; 
}
