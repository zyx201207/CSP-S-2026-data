#include<bits/stdc++.h>
using namespace std;
int n,m,s[500008],cn[200008],an[200008];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cn[s[j]]++;
			if(cn[s[j]]==1) continue;
			int o=j;
			while(!(s[o]==s[j] && o!=j)){
				o--;
				cn[o]--;
			}
		}
		for(int j=1;j<=m;j++){
			if(cn[j]!=0){
				an[j]+=1;
				cn[j]=0;
			}
	    }
	}
	for(int j=1;j<=m;j++){
		cout<<an[j]<<' ';
	}
	return 0;
} 