#include<bits/stdc++.h>
using namespace std;
long long int a[200010];
long long int n;
long long int m;
//int zonghe;
long long int maxx=-1000000;
long long int yxt=-10000000; 
void DFS(long long int xx,long long int cnt,long long int zonghe){
	if(cnt!=0) zonghe=zonghe & a[xx];
	cnt+=1;
	if(cnt==m){
		maxx =max(maxx,zonghe);
		return ;
	}
	for(int i=xx+1;i<=n;i++){
		DFS(i,cnt,zonghe);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		yxt=max(yxt,a[i]);
	}
	if(m==1){
		cout<<yxt;
		return 0;
	}
	if(m==n){
		long long xian=a[1];
		for(int i=1;i<=n;i++){
			xian = xian & a[i];
		}
		cout<<xian;
		return 0;
	}
	for(int i=1;i<=n;i++){
		DFS(i,0,a[i]);
	}
	cout<<maxx;
	return 0;
} 
