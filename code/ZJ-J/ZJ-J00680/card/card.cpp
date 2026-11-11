#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int tn,kinds,a[500005],g[500005],cnt[300005];
int link(int x){
	for(int i=x;i<=tn;i++){
		g[i]=0;
	}
	return 0;
}
int find_int(int x){
	for(int i=1;i<=tn;i++){
		if(g[i]==x) return i;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>tn>>kinds;
	for(int i=1;i<=tn;i++){
		cin>>a[i];
	}
	for(int i=1;i<=tn;i++){
		link(0);
		for(int j=i;j<=tn;j++){
			if(find_int(a[j])!=-1) link(find_int(a[j]));
			g[j]=a[j];
		}
		for(int i=1;i<=tn;i++){
			if(g[i]!=0) cnt[i]++;
		}
	}
	for(int i=1;i<=tn-1      ;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}