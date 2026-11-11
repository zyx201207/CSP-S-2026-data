#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][25],t[505][25],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		a[i][0]=i;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		int jack=0;
		jack+=w[x[i]]+w[y[i]];
		int flag=0,flga=0;
		for(int h=1;h<=n;h++){
			for(int j=1;j<=k[i];j++){
				if(a[h][j]==x[i]) flag=h;
				else if(a[h][j]==y[i]) flga=h;
			}
		}
		bool fool=false;
		for(int h=1;h<=k[flag];h++){
			for(int j=1;j<=k[flga];j++){
				if(a[flag][h]==a[flga][j]){
					jack+=t[flag][a[flag][h]]+t[flga][a[flga][j]];
					cout<<jack<<endl;
					fool=true;
					break;
				}
			}
			if(fool==true) break;
		}
		if(fool==true) continue;
		
		int b=0;
		while(true){
			b++;
			bool hool=false;
			int e,s;
			if(b==flag||b==flga) continue;
			for(int h=1;h<=k[flag];h++){
				for(int j=1;j<=k[b];j++){
					if(a[flag][h]==a[b][j]){
						fool=true;
						s=h;
						e=a[b][j];
						break;
					}
				}
				if(fool==true) break;
			}
			if(fool==false) continue;
			fool=false;
			int r,z;
			for(int h=1;h<=k[flga];h++){
				for(int j=1;j<=k[b];j++){
					if(a[flga][h]==a[b][j]){
						fool=true;
						z=h;
						r=a[b][j];
						break;
					}
				}
				if(fool==true) break;
			}
			if(fool==true){
				jack+=t[flag][a[flag][s]]+t[flga][a[flga][z]]+t[b][e]+t[b][r];
				cout<<jack<<endl;
				break;
			}
		}
	}
	return 0;
} 
