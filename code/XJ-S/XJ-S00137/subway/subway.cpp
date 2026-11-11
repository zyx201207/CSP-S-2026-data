#include<bits/stdc++.h>
using namespace std;
int a[502][500002],b[500002],c[502],w[500002],minx=INT_MAX;
long long c1,n,m,d,q;
void f(int s,int p,int t);
void f2(int s,int p,int t){
	c[s]=t;
	int i=1;
	while(a[s][i]!=0){
		if(b[i]>t+a[s][i]){
			f(i,p,(t+a[s][i]));
		}
		i++;
	}
}
void f(int s,int p,int t){
	b[s]=p;
	if(s==p){
		minx=min(minx,t);
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(a[i][s]>0&&c[i]>t+a[i][s]){
			f2(i,p,t+a[i][s]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c1>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			int s1,s2;
			cin>>s1>>s2;
			a[i][s1]=s2;
		}
	}
	while(q--){
		int s,p;
		cin>>s>>p;
		f(s,p,w[s]);
		cout<<minx<<endl;
		for(int i=1;i<=n;i++){
			c[i]=0;
		}
		for(int j=1;j<=m;j++){
			b[j]=0;
		}
		minx=INT_MAX;
	}
}
