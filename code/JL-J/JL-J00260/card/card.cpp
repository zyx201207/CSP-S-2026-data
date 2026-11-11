#include <bits/stdc++.h>
using namespace std;
int a[500001],ml[300001],t[500001];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=m;i++)ml[i]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++){
		for(int k=j;k<=n;k++){
			if(!ml[a[k]]){
				ml[a[k]]=k;
			}
			else{
				for(int f=j;f<=k;f++){
					if(ml[a[f]]>ml[a[k]]){
						ml[a[f]]=0;
					}
				}
			}
		}
		for(int f=0;f<=m;f++){
			if(ml[f]){
				t[f]++;
				ml[f]=0;
			}
		}
	}
	for(int p=1;p<=m;p++){
		cout<<t[p]<<' ';
	}
	return 0;
}
