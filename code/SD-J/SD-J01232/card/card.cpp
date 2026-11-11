#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[500005],b[300005],c[500005],top=0,d[300005],l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	c[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,-1,sizeof(b));
		top=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=-1){
				top=b[a[j]]-1;
			}top++;
			c[top]=a[j];
			b[a[j]]=top;
		}for(int j=1;j<=top;j++){
			d[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
