#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[300005];
int now[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		int e=0,j=i;
		while(j<=n){
			if(t[a[j]]==0){
				e++;
				now[e]=a[j];
				t[a[j]]=e;
			}
			else {
				for (int k=t[a[j]]+1;k<=e;k++){
					t[now[k]]=0;
				}
			}
			e=t[a[j]];
			j++;
		}
		for (int k=1;k<=e;k++){
			ans[now[k]]++;
			t[now[k]]=0;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


