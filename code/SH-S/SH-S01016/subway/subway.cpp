#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,n,m,bh,x[505],y[505][505],ans=20000005,st,ed,rst[505],red[505],rstn,redn,rsame[505][505],num;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>bh>>a>>n>>b>>m;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	for(int i=0;i<a;i++){
		cin>>c;
		for(int j=0;j<c;j++){
			cin>>d;
			cin>>y[i][d-1];
			for(int l=0;l<i;l++){
				if(y[l][d-1]!=0){
					if(rsame[i][l]==0){
						rsame[i][l]=d-1;	
						rsame[l][i]=d-1;
					}
					else{
						if(y[i][rsame[i][l]]+y[l][rsame[i][l]]>y[l][d]+y[i][d]){
							rsame[i][l]=d-1;
							rsame[l][i]=d-1;	
						}
					}
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cin>>st>>ed;
		st--;
		ed--;
		for(int j=0;j<a;j++){
			if(y[j][st]!=0){
				rst[rstn++]=j;
			} 
			if(y[j][ed]!=0){
				red[redn++]=j;
			}
		}
		for(int l=0;l<rstn;l++){
			for(int ll=0;ll<redn;ll++){
				if(rst[l]==red[ll]){
					ans=min(ans,y[rst[l]][st]+y[red[ll]][ed]);
				}
				else if(rsame[rst[l]][red[ll]]){
					ans=min(ans,y[rst[l]][st]+y[red[ll]][ed]+y[rst[l]][rsame[rst[l]][red[ll]]]+y[red[ll]][rsame[rst[l]][red[ll]]]);
				}
				else{
					continue;
				}
			}
		}
		cout<<ans+x[st]+x[ed]<<endl;
		rstn=0;
		redn=0;
		ans=20000005;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
