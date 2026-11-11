#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<string>
#include<cstring>
using namespace std;
int n,m,v[300005],c[300005],a[500005],pos=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(v,-1,sizeof(v));
	for(int i=n;i>=1;i--){
		if(v[a[i]]==-1){
			v[a[i]]=i;
		}
		for(int k=v[a[i]];k<=n;k=v[a[k]]+1){
			c[a[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" "; 
	}
	return 0;
} 
