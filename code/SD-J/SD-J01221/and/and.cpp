#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
long long po[35];
struct cf{
	int id;
	int ch;
}x[N];
/*
int dfs(int x,int cnt){
	if(cnt==m){
		return ;
	}
	else{
		return dfs()
	}
}
*/
void init(){
	int s=2;
	po[0]=1;
	for(int i=1;i<=32;i++){
		po[i]=s;
		s*=2;
	}
}
bool cmp(cf xx,cf yy){
	if(xx.ch==yy.ch) return xx.id<yy.id;
	else return xx.ch>yy.ch; 
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=31;j++){
			if(po[j]>=a[i]&&po[j-1]<a[i]){
				x[++cnt].id=i;
				x[cnt].ch=a[i];
			}
		}
	}
	sort(x+1,x+1+cnt,cmp);
	/*
	for(int i=1;i<=n;i++){
		cout<<x[i].ch<<' ';
	} 
	*/
	long long tm=a[x[1].id];
	for(int i=2;i<=m;i++){
		tm=tm&a[x[i].id];
	}
	cout<<tm;
	return 0;
}
