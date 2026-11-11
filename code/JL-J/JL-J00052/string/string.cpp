#include <bits/stdc++.h>
using namespace std;
struct node{
	int s;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long m=0;
	cin>>n;
	node a[n+2];
	a[0].s=0;
	a[n+1].s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		m+=a[i].s;
	}
	int ppl=0,ppr=n+1;
	long long ans=0,pl=0,pr=0,zbl=0,zbr=0;
	m=(m+1)/2;
	while(zbl<=m && zbr<=m){
		if(pl<=0){
			ppl++;
			pl+=a[ppl].s;
			zbl+=a[ppl].s;
		}
		if(pr<=0){
			ppr--;
			pr+=a[ppr].s;
			zbr+=a[ppr].s;
		}
		long long ss=min(pl,pr);
		if(a[ppl].c!=a[ppr].c)ans+=ss;
		pl-=ss;
		pr-=ss;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

