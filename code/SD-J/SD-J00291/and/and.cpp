#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
long long n,m,p[MAXN],y[MAXN]={0};
string g[MAXN];
int main(){
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	sort(p,p+n);
	for(int i=n-m;i<n;i++){
		int t=p[i],o=1;
		while(t!=0){
			y[i]=y[i]+t%2*o;
			t=t/2;
			o=o*10;
		}
	}
	for(int i=n-m;i<n;i++){
		g[i]=char(y[i]);
	}
	int l=g[n-m].size();
	for(int i=n-m;i<n;i++){
		if(i+1==n) break;
		string r;
		for(int j=0;j<=l;j++){
			if(g[i][j]=='1'&&g[i][j]==g[i+1][j]){
				r+='1';
			}
			else{
				r+='0';
			}
		}
		g[i+1]=r;
	}
	int w=g[n-1]-'A',ans=0,b=1;
	while(w!=0){
		ans=ans+w%10*b;
		w=w/10;
		b=b*2;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
