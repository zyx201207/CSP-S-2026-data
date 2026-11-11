#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5, M=3e5+5;
long long n, m, a[N];
int ans[N], t=1;
int flag[M];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++){
			if(flag[a[i]]!=0){
				for(int j=flag[a[i]] +1;j<=i;j++){
					 flag[a[j]]=0;
				}
			}
			flag[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(flag[i]){
				ans[i]++;
				flag[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
