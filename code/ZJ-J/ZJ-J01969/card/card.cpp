#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int b[N];
int dd[N];
struct node{
	bool vis;
	int id;
}x[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int cnt;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!x[b[j]].vis){
				x[b[j]].vis=1;
				x[b[j]].id=++cnt;
				dd[cnt]=b[j];
			}else{
			}
		}
	}
	return 0;
}
