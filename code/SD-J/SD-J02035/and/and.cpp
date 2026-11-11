#include<vector>
#include<bits/stdc++.h>
#define lbt(x) ((x)&-(x))
using namespace std;
	int n,m,a[200005],sja,sjlo,len[45],kt,lsn,sl;
	bool p[200005][32],ph[200005];
	vector<int>vb[45];
	vector<int>vh,jl;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sja=a[i];
		while(sja){
			sjlo=log2(lbt(sja));
			p[i][sjlo]=1;
			sja-=lbt(sja);
			len[sjlo]++;
			vb[sjlo].push_back(i);
		}
	}
	bool lp=0; 
	for(int i=32;i>=0;i--){
		if(len[i]>=m){
			lp=1;
			kt=i;
			break;
		}
	}
	if(!lp){
		cout<<0;
		return 0;
	}
	int ib=kt-1,js=0;
	for(int i=0;i<len[kt];i++){
		lsn++;
		vh.push_back(vb[kt][i]);
		ph[vb[kt][i]]=1;
	}
	while(ib>=0){
		js=0;
		jl.clear();
		for(int i=0;i<lsn;i++){
			if(p[vh[i]][ib]&&ph[vh[i]]){
				js++;
				jl.push_back(vh[i]);
			}
		}
		if(js>=m){
			for(int i=0;i<len[kt];i++){
				ph[vb[kt][i]]=0;
			}
			for(int i=0;i<js;i++){
				ph[jl[i]]=1;
			}
		}
		ib--;
	}
	int jh=0;
	for(int i=1;i<=n;i++){
		if(ph[i]){
			if(jh==0){
				sl=a[i];
			}
			else{
				sl=(sl&a[i]);
			}
			jh++;
			if(jh==m){
				cout<<sl;
				return 0;
			}
		}
	}
	
	
	
	
	
	
	
	
	return 0;
} 
