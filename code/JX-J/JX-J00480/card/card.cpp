#include<bits/stdc++.h>
using namespace std;
int n,m,k[500010],d[500010],len;
int y[500010],ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>k[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){d[j]=0;y[j]=0;}
		len=0;
		for(int j=i;j<=n;j++){
			len++;
			d[len]=k[j];
			if(y[k[j]]!=0){
//				cout<<y[k[j]]+1<<"~"<<len<<":";
				for(int p=y[k[j]]+1;p<=len;p++){y[d[p]]=0;/*cout<<d[p]<<" ";*/d[p]=0;}
				len=y[k[j]]+1;
			}
			else y[k[j]]=len;
//			cout<<"*";
//			for(int p=1;p<=n;p++) cout<<d[p]<<" ";
//			cout<<endl;
//			cout<<"!";
//			for(int j=1;j<=n;j++) cout<<y[k[j]]<<" ";
//			cout<<endl;
		}
//		for(int j=1;j<=n;j++) cout<<d[j]<<" ";
//		cout<<endl;
		for(int j=1;j<=n;j++)
			if(d[j]!=0) ans[d[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
//verity,help me!!!
