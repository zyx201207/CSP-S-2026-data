#include<bits/stdc++.h>
using namespace std;
int w[500009],k[509],a[500009][500009],t[500009][500009];
int c,n,m,d,q;
vector<pair<int,pair<int,int>>> mp;

int existin(int aa,int bb){
	for(int i=1;i<=k[aa];i++){
		if(bb==a[aa][i]) return 1;
	}
	return 0;
}

int search(){
	for(int i=1;i<=m;i++){
		if(existin(1,i)==1 && existin(2,i)==1) return i;
	}
	return 0;
}

int solve2(int st,int ed){
	int temp=0;
	if(existin(1,st)==1){
		temp+=t[1][st];
		if(existin(1,ed)==1) temp+=t[1][ed];
		else{
			temp+=t[1][search]+t[2][search]+t[2][ed]
		}
	}
	else{
		temp+=t[2][st];
		if(existin(2,ed)==1) temp+=t21][ed];
		else{
			temp+=t[2][search]+t[1][search]+t[1][ed]
		}
	}
	return w[st]+w[ed]+temp;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int temp,temp2,temp3;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		if(n==1) cout<<w[st]+w[ed]+t[1][st]+t[1][ed]<<"\n";
		else if(n==2) cout<<solve2(st,ed)<<"\n";
	}
	return 0;
}

