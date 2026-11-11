#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001]={0};
string s[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)s[i]=' ';
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(s[a[i]].size()!=1){
			for(int j=1;j<=s[a[i]].size();j++)ans[s[a[i]][j]-'0']++;
			continue;
		}
		for(int j=i;j<=n;j++){
			for(int k=n;k>=j;k--){
				if(a[k]==a[j]){
					s[a[i]]+=a[j]+'0',j=k;
					break;
				}
			}
		}
		for(int j=1;j<=s[a[i]].size();j++)ans[s[a[i]][j]-'0']++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
