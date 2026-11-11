#include<bits/stdc++.h>

using namespace std;

int a[500050],n,m,b[500050],ans[300030];

void f(int x){
	int flag=0;
	memset(b,0,sizeof(b));
	for(int i=x;i<=m;i++){
		b[i]=a[i];
		flag=0;
		for(int k=x;k<i;k++){
			if(b[k]==0) continue;
			if(b[k]==b[i]){
				flag=1;
			}
			if(flag) b[k]=0;
		}
	}
	for(int i=x;i<=m;i++){
		if(b[i]) ans[b[i]]++;
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		
		f(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}