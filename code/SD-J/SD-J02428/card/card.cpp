#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000006],b[600005],s[600005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j<b[a[j]]){
				j=b[a[j]]-1;
			}
			else{
				s[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}

