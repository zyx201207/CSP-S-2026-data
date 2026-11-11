#include<bits/stdc++.h>
using namespace std;
int w[1000],k[1000],tim[1000][1000],ppd[1000][0000],a[1000][1000],t[1000][1000],q,x[1000],y[1000],pd[1000][1000],money[1000][1000],pro[1000][1000];
int main(){
//	n:地铁线路数 
//	m:地铁站台数 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	ios::sync_with_stdio(false),cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<k[i];j++)
		for(int s=j;s<=k[i];s++){
			pd[a[i][j]][a[i][s]]=1;
			ppd[a[i][j]][a[i][s]]=1;
			if(money[a[i][j]][a[i][s]]>0&&t[i][a[i][j]]+t[i][a[i][s]]<money[a[i][j]][a[i][s]])
			money[a[i][j]][a[i][s]]=t[i][a[i][j]]+t[i][a[i][s]];
			tim[a[i][j]][a[i][s]]=t[i][a[i][j]]+t[i][a[i][s]];
		}
	}
	
	
	
	
	for(int i=1;i<=q;i++){
		for(int j=1;j<=m;j++)
		    for(int s=1;s<=m;s++)
		    	pd[j][s]=ppd[j][s];
		for(int j=1;j<=m;j++)
			for(int s=1;j<=m;s++)
				money[j][s]=tim[j][s];
		for(int j=1;j<=30;j++)
			for(int s=1;s<=m;s++)
				pro[i][j]=0;
		for(int j=1;j<=30;j++)
			for(int s=1;s<=m;s++)
				pro[i][j]=0;				
		cin>>x[i]>>y[i];
		int prc=1,prk=1;
		for(int j=1;j<=m;j++){
			if(pd[x[i]][j]==1) {
				pro[prc][j]=1;
			}
		}
		prc++;
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(pro[prc][j]==1){
				for(int s=1;s<=m;s++){
					if(pd[j][s]==1&&s!=x[i]){
						pro[prc][s]==1;
						if(money[x[i]][s]==0) money[x[i]][s]=money[x[i]][j]+money[j][s];
						else money[x[i]][s]=min(money[x[i]][s],money[x[i]][j]+money[j][s]);
					}
				}
			}
		}				
		cout<<money[x[i]][y[i]]+w[x[i]]+w[y[i]];																						
	}
//	cout<<money[x[i]][y[i]]+w[x[i]]+w[y[i]];
//	w[i]: 第i个地铁站的站口到站厅所花费的时间 
//	a[i][j]:第i条线路经过第a[i][j]地铁站 
//	t[i][j]:第j个地铁站的站厅到第i条线路的站台所花费的时间 
//  money[m][n]:从第m个地铁站的站厅到第n个地铁站的站厅所花费的最少时间 
//pd[m][n]表示m与n这两个站台可以互通 
}