#include<bits/stdc++.h>
using namespace std;
long long w[500005],a[50002][502],t[50002][502],ch[10005][3],aa[500002];
long long n,m,c,d,q,he,mmin=999999,tx,tx1,u;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int ii=1;
	for(int j=1;j<=n;j++){
		cin>>aa[j];
		for(int i=1;i<=aa[j];i++){
			cin>>a[i][ii]>>t[i][ii];
		}
		ii++;
	}
	for(int j=1;j<=q;j++){
		cin>>ch[j][1]>>ch[j][2];
	}//输入
	for(int i=1;i<=q;i++){
		he=0;
		mmin=99999;
		tx=0;
		int u=0;
		tx1=0; 
		for(int k=1;k<=n;k++){
			for(int j=1;j<=aa[k];j++){
				//cout<<j<<" "<<k<<'\n';
				if(a[j][k]==ch[i][1]){
					mmin=min(mmin,t[j][k]);
					if(mmin==t[j][k]){
						tx=k;
					}
					u=1;
					break;
				}	
			}
			if(u==1){
				break;
			}
		}
		//起点最短时间
		he=he+mmin+w[ch[i][1]];
		mmin=99999;
		u=0;
		for(int k=1;k<=n;k++){
			for(int j=1;j<=aa[k];j++){
				if(a[j][k]==ch[i][2]){
					mmin=min(mmin,t[j][k]);
					if(mmin==t[j][k]){
						tx1=k;	
					}
					u=1;
					break;
				}	
			}
			if(u==1){
				break;
			}
		}
		//终点最短时间
		he=he+mmin+w[ch[i][2]];
		
		if(tx==tx1){
			cout<<he<<'\n';
		}//线路一样 
		else{
			//cout<<tx<<" "<<tx1<<" ";
			int ii=1;
			for(int k=1;k<=n;k++){
				u=0;
				if(k==tx){
					for(int l=1;l<=aa[tx];l++){
						int v=a[ii][k];	
						for(int j=1;j<=aa[tx1];j++){
							//cout<<a[j][tx1]<<" "<<v<<'\n';
							if(a[j][tx1]==v){
								he+=t[j][tx1]+t[ii][k];
								//cout<<he<<" ";
								u=1;
								break;
							}
						}
						if(u==1){
							break;
						}
						ii++;
					}
					
				}
				if(k==tx1){
					int v=a[ii][k];
					for(int j=1;j<=aa[tx];j++){
						if(a[j][tx]==v){
							he+=t[j][tx]+t[ii][k];
							//cout<<he<<" ";
							break;
						}
					}
					ii++;
				}
			}
			cout<<he<<'\n';
		}
}
	return 0;
} 