#include<bits/stdc++.h>
#include<cstdio>
#include<queue>
using namespace std;
int maax,m,n;
int l[500010];
int as; 

void hui(int cengshu,int zhi){
	//	cout<<cengshu;

	if(cengshu>m){
	//	cout<<maax<<" ";
		maax=max(maax,as);
		return;
	} 
	

	for(int i=zhi+1;i<=n;i++){
		if(cengshu==1){
		as=l[i];
	}
		int lin=as;
		as&=l[i];
		hui(cengshu+1,i);
		as=lin;
		
	}
	
	
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out", "w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	hui(1,0);
	cout<<maax;
	return 0;
	}
