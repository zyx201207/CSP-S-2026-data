#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[500005],s[500005],top,f[300005],ans[300005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		top=0;
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				f[a[j]]=top+1;
			}
			else{
				top=f[a[j]]-1;
			}
			top++;
			s[top]=a[j];
		}
		for(int j=1;j<=top;j++){
			ans[s[j]]++;
//			cout<<s[j]<<' ';
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

