#include<bits/stdc++.h>
using namespace std;
long long n,m,a[567891],e[345678];
struct node{
	long long b,c,k;
}d[345678];
bool cp(node A,node B){
	return A.b<B.b;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		d[i].b=-1;
		d[i].c=0;
		d[i].k=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=n;i;i--){
		if(d[a[i]].b==-1)d[a[i]].b=i;
		d[a[i]].c++;
	}
	sort(d+1,d+m+1,cp);
	for(int i=m;i;i--){
		e[d[i].k]=i;
//		cout<<d[i].b<<" "<<d[i].c<<" "<<d[i].k<<endl;
	}
	for(int i=1;i<=m;i++){
		d[e[a[d[i].b+1]]].c+=d[i].c;
	}
	for(int i=1;i<m;i++)printf("%lld ",d[e[i]].c);
	cout<<d[e[m]].c<<endl;
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
