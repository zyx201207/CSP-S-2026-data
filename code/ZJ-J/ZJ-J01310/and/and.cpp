#include<bits/stdc++.h>
const int slen=2e5+10;
using namespace std;
int a[slen],maxx=-1,n,m;
void b(int y,int s,int t){
	if(t==m){
		maxx=max(maxx,y);
		return;
	}
	for(int i=s;i<=n;i++){
		b(y&a[i],i+1,t+1);
	}
}
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q=1;
	for(int i=1;i<=31;i++) q=q*2;
	b(q-1,1,0);
	cout<<maxx;
	return 0;
}
