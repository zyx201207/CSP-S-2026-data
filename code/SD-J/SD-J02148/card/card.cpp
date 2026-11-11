#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int st[N];
int top;
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=top;k++){
				if(st[k]==a[j]){
					top=k-1;
					break;
				}
			}
			st[++top]=a[j];
		}
		for(int j=1;j<=top;j++){
			ans[st[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}
