#include<bits/stdc++.h>
using namespace std;
int a[500010],s[300010],play[500010],la[300010];
int m,n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=1;j<=m;j++) la[j]=0;
		for(int j=i;j<=n;j++){
			if(la[a[j]]==0) la[a[j]]=t+1,t=t+1;
			else t=min(la[a[j]],t+1);
			play[t]=a[j];
		}
		for(int j=1;j<=t;j++){
			s[play[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
