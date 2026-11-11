#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[500005];
int n,m;
void solve(int s){
	int now=s;
	for(int i=s;i<=n;i++){
		for(int j=s;j<=i;j++){
			if(a[i]==a[j]&&i!=j){
				now=i;
			}
		}
	}
	for(int i=now;i<=n;i++){
		ans[a[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	} 
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)solve(i);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
