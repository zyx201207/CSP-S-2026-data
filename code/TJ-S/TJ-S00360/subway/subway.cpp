#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int kt[500010];//Õ¾¿Úµ½Õ¾Ìü 
int zcnt[500];
int tz[500][500];


int ans;
int st,la;

int f(int idx){
	if(idx==la){
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(tz[i][idx]>0){
			for(int j=1;j<=zcnt[i];j++){
				if(tz[i][j]>0 && j!=idx){
					ans+=tz[i][j];
					ans+=tz[i][idx];
					tz[i][j]=-1;
					tz[i][idx]=-1;
					f(j);
				}
			}
		}
	}
}



int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i=1;i<=m;i++){
		cin >> kt[i];
	}
	for(int i=1;i<=n;i++){
		cin >> zcnt[i];
		for(int j=1;j<=zcnt[i];j++){
			int a;
			cin >> a >> tz[i][a];
		}
	}
	
	
	while(q--){
		
		cin >> st >> la;
		ans=kt[st]+kt[la];
		f(st);
		cout << ans << endl;
		
	}
	
	return 0;
	
}

















