#include<bits/stdc++.h>
using namespace std;
int n,m,a[500006],jyz[300006];
int t[500006];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		t[i]=a[i];
	}for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			bool flag=0;
			for(int k=i;k<j;k++){
				if(a[k]==a[j]) flag=1;
				if(flag) a[k]=0;
			}
		}for(int j=i;j<=n;++j){
			if(a[j]!=0) jyz[a[j]]++;
		}for(int j=i+1;j<=n;++j){
			a[j]=t[j];
		}
	}for(int i=1;i<=m;++i){
		cout<<jyz[i]<<" ";
	}
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
