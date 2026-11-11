#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n,m,x=1;
int a[N],b[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for (int j=i;j<=n;j++,x++){
			for (int k=1;k<=x;k++)
				if (b[k]==a[j]){
					for (int z=k;z<=x;z++)
						b[z]=0;
				break;
			}
			b[x]=a[j]; 
		}
		for (int j=1;j<=x;j++){
			if (b[j])
				ans[b[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		if (ans[i])
			cout << ans[i]<<" ";
	}	
	return 0;
} 
