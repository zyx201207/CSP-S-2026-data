#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10; 
long long c,n,m,d,q,w[N]={0},x,y,u=0,l[N]={0},k[N]={0},min1=N;
long long a1[N]={0},a2[N]={0},t1[N]={0},t2[N]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(n==1){
		cin>>k[1];
		for(int i=1;i<=k[1];i++){
			cin>>a1[i]>>t1[i];
		}
	}else if(n==2){
		cin>>k[1];
		for(int i=1;i<=k[1];i++){
			cin>>a1[i]>>t1[i];
		}
		cin>>k[2];
		for(int i=1;i<=k[2];i++){
			cin>>a2[i]>>t2[i];
		}
	}
	while(q--){
		u=0;
		int hh=0;
		memset(l,0,sizeof(l));
		if(n==1){
			cin>>x>>y;
			for(int i=1;i<=k[1];i++){
				if(a1[i]==x || a1[i]==y){
					u+=t1[i];
				}
				
			}
			u+=w[x]+w[y];
			cout<<u<<endl;
		}else if(n==2){
			
			cin>>x>>y;
			for(int i=1;i<=k[1];i++){
				if(a1[i]==x || a1[i]==y){
					hh++;
				}
			}
			if(hh==2){
				for(int i=1;i<=k[1];i++){
					if(a1[i]==x || a1[i]==y){
						u+=t1[i];
					}
				}
			}else{
				for(int i=1;i<=k[1];i++){
					for(int j=1;j<=k[2];j++){
						if(a1[i]==a2[j]){
							min1=min(min1,t1[i]+t2[j]);
						}
					}
				}
				u+=min1;
				for(int i=1;i<=k[1];i++){
					if(a1[i]==x || a1[i]==y){
						u+=t1[i];
					}
				}
				for(int i=1;i<=k[2];i++){
					if(a2[i]==x || a2[i]==y){
						u+=t2[i];
					}
				}
			}
			u+=w[x]+w[y];
			cout<<u<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
