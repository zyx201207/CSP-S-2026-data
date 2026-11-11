#include<bits\stdc++.h>
using namespace std;
int w[10005],a1[10005],a2[10005],t1[10005],t2[10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q,k1,k2,x,y,t=0;
	cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		cin>>k1;
		for(int i=1;i<=k1;i++){
			cin>>a1[i]>>t1[i];
		}
		cin>>k2;
		for(int i=1;i<=k2;i++){
			cin>>a2[i]>>t2[i];
		}
		int a,b;
		for(int i=1;i<=k1;i++){
			for(int j=1;j<=k2;j++){
				if(a1[i]==a2[j]){
					a=i;
					b=j;
				}
			}
		}
	while(q--){
		cin>>x>>y;
		int xx,yy,xxx,yyy;
		for(int i=1;i<=k1;i++){
			if(a1[i]==x){
				xx=1;
				xxx=i;
			}
			if(a1[i]==y){
				yy=1;
				yyy=i;
			}
		}
		if(xx!=1||yy!=1){
			for(int i=1;i<=k2;i++){
			if(a2[i]==x){
				xx=2;
				xxx=i;
			}
				if(a2[i]==y){
					yy=2;
					yyy=i;
				}
			}
		}
		if(xx==yy){
			if(xx==1){
				t+=w[x]+w[y];
				for(int i=xxx;i<=yyy;i++){
					t+=t1[i];
				}
			}else{
				t+=w[x]+w[y];
				for(int i=xxx;i<=yyy;i++){
					t+=t2[i];
				}
			}
		}else{
			if(xx==1){
				t+=w[x]+w[y];
				for(int i=xxx;i<=a;i++){
					t+=t1[i];
				}
				for(int i=b;i<=yyy;i++){
					t+=t2[i];
				}
			}else{
				t+=w[x]+w[y];
				for(int i=xxx;i<=b;i++){
					t+=t2[i];
				}
				for(int i=a;i<=yyy;i++){
					t+=t1[i];
				}
			}			
		}
		cout<<t;
		t=0;
	}
	return 0; 
} 
