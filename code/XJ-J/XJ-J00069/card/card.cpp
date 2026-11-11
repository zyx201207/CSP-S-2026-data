#include<bits/stdc++.h>
using namespace std;
int b[500010],d[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k;cin>>n>>m;k=n;
	for(int i=0;i<n;i++)
		cin>>b[i];
	while(n--){
		int c[300010];
		for(int i=1;i<=m;i++)
			c[i]=0;
		for(int i=n;i<k;i++){
			if(c[b[i]]>0){
				for(int j=i-1;j>=n&&b[j]!=b[i];j--){
					if(c[b[j]])c[b[j]]--;
				}
			}else c[b[i]]++;
		/*	for(int i=1;i<=m;i++)
				cout<<c[i]<<' ';
			cout<<endl;*/
		}//cout<<endl;
		for(int i=1;i<=m;i++)
			if(c[i])d[i]++;
	}for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
