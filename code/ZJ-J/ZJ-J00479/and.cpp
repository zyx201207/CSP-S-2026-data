#include<bits/stdc++.h>
using namespace std;
int a[200009];
bool b[200009];
int n,m,ans;
void xnxf(int x){
	if(x==m){
		int y=0,z;
		for(int i=1;i<=n;i++){
			if(b[i]&&y==1) z=a[i];
			else if(b[i]) z=z^a[i];
		}ans=max(ans,z);
	}
	if(x>m) return ;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			x+=1;
			b[i]=1;
			xnxf(x);
			b[i]=0;
			x-=1;
		}
	}
}
int main(){
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}xnxf(1);
	cout<<ans;
	return 0;
}