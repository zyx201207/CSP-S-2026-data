#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,v1,v2;
int w[500005];
int mp[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<5005;i++) for(int j=0;j<5005;j++) mp[i][j]=0;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>v1>>v2;
			mp[i][v1+500]=v2;
			mp[v1+500][i]=v2;
		}
	}
	for(int k=0;k<m+500;k++){
		if(k<500&&k>=n) continue;
		for(int i=0;i<m+500;i++){
			if(i<500&&i>=n) continue;
			for(int j=0;j<m+500;j++){
				if(j<500&&j>=n) continue;
				if(mp[i][k]&&mp[j][k]){
					if(mp[i][j]){
						if(mp[i][j]>mp[i][k]+mp[j][k]){
							mp[i][j]=mp[i][k]+mp[j][k];
							mp[j][i]=mp[i][k]+mp[j][k];
						}
					}
					else{
						mp[i][j]=mp[i][k]+mp[j][k];
						mp[j][i]=mp[i][k]+mp[j][k];
					} 
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		cin>>v1>>v2;
		cout<<w[v1-1]+w[v2-1]+mp[v1+500][v2+500]<<endl;
	}
	return 0;
}