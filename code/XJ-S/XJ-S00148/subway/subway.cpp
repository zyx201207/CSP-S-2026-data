#include<bits/stdc++.h>
using namespace std;
struct dian{
	int i,t;
};
struct xian{
	int l,r,t;
}pai[500003];
int l=0;
vector<dian>kou[500003];
vector<int>huandian;
vector<int>huanxian[503];
int huan[503][503];
int pan[503][503];
bool cmp(xian a,xian b){
	return a.t<b.t;
}
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		dian t;
		cin>>t.t;
		t.i=0;
		kou[i].push_back(t);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			dian t;
			cin>>t.i>>t.t;
			kou[t.i].push_back({i,t.t});
			if(kou[t.i].size()==3)huandian.push_back(t.i);
		}
	}
	for(int i=0;i<huandian.size();i++){
		for(int j=1;j<kou[huandian[i]].size();j++){
			for(int jj=1;jj<kou[huandian[i]].size();jj++){
				if(jj==j)continue;
				pai[l++]={kou[huandian[i]][j].i,kou[huandian[i]][jj].i,kou[huandian[i]][j].t+kou[huandian[i]][jj].t};
				huanxian[kou[huandian[i]][j].i].push_back(kou[huandian[i]][jj].i);
				huanxian[kou[huandian[i]][jj].i].push_back(kou[huandian[i]][j].i);
			}
		}
	}
	int i=0;
	while(i<l){
		sort(pai+i,pai+l,cmp);
		if(pan[pai[i].l][pai[i].r]==1){
			i++;
			continue;
		}
		pan[pai[i].l][pai[i].r]=1;
		pan[pai[i].r][pai[i].l]=1;
		if(huan[pai[i].l][pai[i].r]==0){
			huan[pai[i].l][pai[i].r]=pai[i].t;
			huan[pai[i].r][pai[i].l]=pai[i].t;
		}
		else{
			huan[pai[i].l][pai[i].r]=min(huan[pai[i].l][pai[i].r],pai[i].t);
			huan[pai[i].r][pai[i].l]=min(huan[pai[i].r][pai[i].l],pai[i].t);
		}
		for(int j=0;j<huanxian[pai[i].l].size();j++){
			if(huanxian[pai[i].l][j]==pai[i].r)continue;
			if(pan[pai[i].l][huanxian[pai[i].l][j]]==1&&pan[huanxian[pai[i].l][j]][pai[i].r]==0){
				if(huan[pai[i].r][huanxian[pai[i].l][j]]==0){
					huan[huanxian[pai[i].l][j]][pai[i].r]=pai[i].t+huan[pai[i].l][huanxian[pai[i].l][j]];
					huan[pai[i].r][huanxian[pai[i].l][j]]=pai[i].t+huan[pai[i].l][huanxian[pai[i].l][j]];
				}
				else{
					huan[huanxian[pai[i].l][j]][pai[i].r]=min(huan[huanxian[pai[i].l][j]][pai[i].r],pai[i].t+huan[pai[i].l][huanxian[pai[i].l][j]]);
					huan[pai[i].r][huanxian[pai[i].l][j]]=min(huan[pai[i].r][huanxian[pai[i].l][j]],pai[i].t+huan[pai[i].l][huanxian[pai[i].l][j]]);
				}
				
				
				pai[l++]={huanxian[pai[i].l][j],pai[i].r,huan[huanxian[pai[i].l][j]][pai[i].r]};
				huanxian[huanxian[pai[i].l][j]].push_back(pai[i].r);
				huanxian[pai[i].r].push_back(huanxian[pai[i].l][j]);
			}
		}
		for(int j=0;j<huanxian[pai[i].r].size();j++){
			if(huanxian[pai[i].r][j]==pai[i].l)continue;
			if(pan[pai[i].r][huanxian[pai[i].r][j]]==1&&pan[huanxian[pai[i].r][j]][pai[i].l]==0){
				if(huan[pai[i].l][huanxian[pai[i].r][j]]==0){
					huan[huanxian[pai[i].r][j]][pai[i].l]=pai[i].t+huan[pai[i].r][huanxian[pai[i].r][j]];
					huan[pai[i].l][huanxian[pai[i].r][j]]=pai[i].t+huan[pai[i].r][huanxian[pai[i].r][j]];
				}
				else{
					huan[huanxian[pai[i].r][j]][pai[i].l]=min(huan[huanxian[pai[i].r][j]][pai[i].l],pai[i].t+huan[pai[i].r][huanxian[pai[i].r][j]]);
					huan[pai[i].l][huanxian[pai[i].r][j]]=min(huan[pai[i].l][huanxian[pai[i].r][j]],pai[i].t+huan[pai[i].r][huanxian[pai[i].r][j]]);
				}
				
				
				pai[l++]={huanxian[pai[i].r][j],pai[i].l,huan[huanxian[pai[i].r][j]][pai[i].l]};
				huanxian[huanxian[pai[i].r][j]].push_back(pai[i].l);
				huanxian[pai[i].l].push_back(huanxian[pai[i].r][j]);
			}
		}
		i++;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<huan[i][j]<<' ';
//			}
//			cout<<endl;
//		}
	}
	while(q--){
		int w,e;
		long long ans=0x3f3f3f3f3f3f3f3f;
		cin>>w>>e;
		for(int i=1;i<kou[w].size();i++){
			for(int j=1;j<kou[e].size();j++){
				long long t=0;
				t+=huan[kou[w][i].i][kou[e][j].i]+kou[w][i].t+kou[e][j].t;
				ans=min(ans,t);
			}
		}
		cout<<ans+kou[w][0].t+kou[e][0].t<<endl;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<huan[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
