#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int d[500010],b[500010];
int s[500010];
struct node{
	bool l=0;
	int id=-1;
} vis[500010];
int x=1;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(vis[a[i]].l==1){
				d[vis[a[i]].id-1]--;
				d[i]++;
				x-=i-vis[a[i]].id;
			}
			vis[a[i]].l=1;
			vis[a[i]].id=x;
			x++;
		}
		for(int i=1;i<=n;i++){
			b[i]=b[i-1]+d[i];
		}
		for(int i=1;i<=n;i++){
			if(b[i]>0){
				s[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}