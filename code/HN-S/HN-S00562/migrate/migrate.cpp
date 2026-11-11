#include<bits/stdc++.h>
#define ll long long
using namespace std;
int w,a[100086],an;
ll n,m;
struct node{
	ll sh,ge,all,num;
}b[100086];
void init(){
	for(int i=1;i<=n;i++){
		b[i].sh=m;b[i].ge=0;
		for(int j=i;j<=n;j++){
			if(a[j]-a[i]>m)break;
			for(int k=j+1;k<=n;k++){
				if(a[k]-a[j]>b[j].sh)break;
				b[k].sh=b[j].sh+a[j]-a[k];
				if(b[k].ge!=0&&b[k].ge!=b[j].ge+1)b[k].ge=b[j].ge+1;
				else b[k].all++;
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j].all==2)an++;
			b[j].all=0;
			b[j].ge=0;
			b[j].sh=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>w;
	cin>>w;
	while(w--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		init();
		cout<<an;
		an=0;
	}
	return 0;
}
