#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long int w[N];
struct node{
	long long int k,a[25];
}sss[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long int c,n,m,p,q,x,y,minn=1234567890,sum=0,f=0;
	cin>>c>>n>>m>>p>>q;
	for(long long int i=1;i<=m;i++){
		cin>>w[i];
	}for(long long int i=1;i<=n;i++){
		cin>>sss[i].k;
		if(sss[i].k>2)f=1;
		for(long long int j=1;j<=sss[i].k;j++){
			cin>>sss[i].a[j];
		}
	}for(int i=1;i<=q;i++){
		cin>>x>>y;
//第一特判——————首
		if(f==0){
		}for(int j=1;j<=n;j++){
			sum+=sss[j].a[j];
		}cout<<sum<<endl;
	}
	return 0;
}