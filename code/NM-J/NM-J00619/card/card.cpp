#include<bits/stdc++.h>
using namespace std;
int n,a[500005],d[500005],e[500005],m;
bool b[500005];
struct bian{
	int l;
	int r;
}c[500005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(b[a[i]]==false){
			b[a[i]]=true;
		}
		else{
			for(int j=d[a[i]]+1;j<i;j++){
				c[a[j]].l=max(d[a[i]]+1,c[a[j]].l);
			}
		}
		c[a[i]].l=1;
		c[a[i]].r=i;
		d[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i].r-c[i].l+1+e[a[i]]<<' ';
	}
	return 0;
}
