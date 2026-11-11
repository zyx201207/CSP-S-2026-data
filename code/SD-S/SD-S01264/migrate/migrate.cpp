#include <bits/stdc++.h>
using namespace std;
int n;const int N=2e6+5;
long long d,x[N];
int a[N];
int s[N],f[N];
void sol(){
	long long tot=0;
	cin>>n>>d;int p=1,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		while(p<i&&x[i]-x[p]>d)++p;
		a[i]=i-p;
		if(a[i]==0){
			tot+=1ll*cnt*(cnt-1)/2;
			cnt=0;
		}++cnt;
	}tot+=1ll*cnt*(cnt-1)/2;
	for(int i=1;i<=n;i++){
		f[i]=a[i];
		if(!a[i])continue;
		int x=i-a[i],y=x+1;
		if(y==i){
			f[i]+=f[x];
		}
		else{
			f[i]+=s[min(y-a[y],x)]-s[x-a[x]-1];
		}
		s[i]=s[i-1]+f[i];
	}
	
	cout<<tot-s[n]<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--)sol();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/
