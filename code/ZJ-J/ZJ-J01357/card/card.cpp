#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
const int lg=500005;
using namespace std;
int p[lg],ptmp[lg],ans[lg],pfast[lg],tms[lg],n1;
map<int,int> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,isap=1,f=1;
	n1=1;
	cin>>n>>m;
	cin>>p[0];
	mp[p[0]]=1;
	tms[0]=1;
	for(int i=1;i<n;i++){
		cin>>p[n1];
		if(p[n1]==p[n1-1]){
			tms[n1-1]++;
			continue;
		}
		tms[n1]=1;
		if(isap){
			if(mp[p[n1]]){
				isap=0;
			} 
			else mp[p[n1]]=1;
		}
		n1++;
	}
	
	if(isap){
		
		for(int i=0;i<=m;i++) ans[i]=0;
		for(int i=0;i<n1;i++){
			ans[p[i]]+=tms[i];
			for(int j=i+1;j<n;j++){
				ans[p[j]]+=tms[i];
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	
	for(int i=0;i<=m;i++) ans[i]=0;
	for(int i=0;i<n1;i++){
		int px=0;
		for(int j=0;j<=m;j++) pfast[j]=-1;
		for(int j=i;j<n1;j++){
			if(pfast[p[j]]==-1){
				pfast[p[j]]=px;
				ptmp[px]=p[j];
				px++;
			}
			else{
				int v=pfast[p[j]];
				for(int k=pfast[p[j]]+1;k<px;k++){
					pfast[ptmp[k]]=-1;
				}
				px=v+1;
			}
		}
		for(int j=0;j<px;j++) ans[ptmp[j]]+=tms[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}