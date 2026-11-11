#include<bits/stdc++.h>
using namespace std;
struct s{
	int a,cha;
};
bool cmp(s x,s y){
	return x.cha>y.cha;
}
long long n,m,z[1000000]; 
s g[1000000];

int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>z[i];
	}
	sort(z,z+n);
	for(int i=0;i<n;i++){
		g[i].a=i;
		g[i].cha=z[i-1]-z[i];
	}
	int ii=0,ans=0;
	sort(g,g+n,cmp);
	while(m--){
		if(z[g[ii].a]<z[g[ii-1].a]){
			z[g[ii].a]++;
		}else{
			ii++;
			ans++;
			m++;
		}
	}
	cout<<ans;
}
