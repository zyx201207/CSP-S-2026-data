#include<bits/stdc++.h>
using namespace std;
int n,m;
queue<int> q;
int a[500005],dc[500005];
int cf,cs,ct;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)q.push(a[j]);
		for(int j=i;j<=n;j++){
			for(int y=1;y<=n;y++){
				if(dc[y]==q.front){
					for(int x=y;x<=n;x++){
						q.push(dc[y]);
						dc[y]=0;
					}
				}
			}
			dc[j]=q.front();
			q.pop();
		}if(dc.length()==1)cf++;
		 else if(dc.length()==2)cs++;
		 else if(dc.length()==3)ct++;
	}cout<<cf<<cs<<ct;
	return 0;
} 
