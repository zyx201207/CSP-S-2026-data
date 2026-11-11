#include<bits/stdc++.h>
using namespace std;
int p[500010]={0};
int z[500010]={0};//¡Ÿ ± 
int ans[300010]={0};

void reading(){
	for(int i=1;i<=500010;i++){
		if(z[i]==0) break;
		ans[z[i]]++;
	}
}

int sreaching(int x){
	for(int i=1;i<=500010;i++){
		if(z[i]==0) return 0;
		if(z[i]==x) return i;
	}
}

int outputing(int x){
	int m=0;
	for(int i=x;i<=500010;i++){
		if(z[i]==0) break;
		z[i]=0;
		m++;
	}
	return m;
}


void cleaning(){
	int gm = outputing(1);
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> p[i];
	}
	
	for(int i=1;i<=n;i++){
		int k = 1;
		for(int j=i;j<=n;j++){
			int f;
			f = sreaching(p[j]);
			if(f!=0) k-=outputing(f);
			z[k] = p[j];
			k++;
		}
		reading();
		cleaning();
	}
	
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}

