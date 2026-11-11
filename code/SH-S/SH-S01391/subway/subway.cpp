#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int to_sta_id,by_sub_id,ti_to_sta,nw_sta_id;
};
int w[500010],fl[500010],ans_ti,lsub_id;
node x;
vector<node> a[510],b[510];
//vector<int> c;
void dfs(int st,int en,int cnt_ti,int sub_id){
	if(st==en){
		lsub_id=sub_id;
		ans_ti=max(cnt_ti,ans_ti);
		return ;
	}
	for(auto i : a[st]){
		if(fl[i.to_sta_id]){
			continue;
		}
		//c.push_back(i.by_sub_id);
		if(i.by_sub_id != sub_id){
			sub_id=i.by_sub_id;
//			cout<<"---"<<i.nw_sta_id<<' '<<i.by_sub_id<<' '<<i.ti_to_sta<<endl;//-------------------
			fl[i.to_sta_id]=1;
			for(auto j : b[st]){
				if(j.by_sub_id==lsub_id){
					cnt_ti+=j.ti_to_sta;
					break;
				}
			}
			dfs(i.to_sta_id,en,cnt_ti+i.ti_to_sta,sub_id);
			fl[i.to_sta_id]=0;		
		}else{
			fl[i.to_sta_id]=1;
			dfs(i.to_sta_id,en,cnt_ti,sub_id);
			fl[i.to_sta_id]=0;
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int aij=0,tij=0,laij=0,ltij=0;
		for(int j=1;j<=k;j++){
			laij=aij;
			ltij=tij;
			cin>>aij>>tij;
			x.by_sub_id=i;
			x.ti_to_sta=ltij;
			x.to_sta_id=laij;
			x.nw_sta_id=aij;
			if(x.ti_to_sta && x.to_sta_id){
				a[aij].push_back(x);
				b[laij].push_back(x);
			}
			x.ti_to_sta=tij;
			x.to_sta_id=aij;
			x.nw_sta_id=laij;
			if(x.ti_to_sta && x.to_sta_id){
				a[laij].push_back(x);
				b[aij].push_back(x);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(auto j : a[i]){
//			cout<<j.to_sta_id<<'-'<<j.by_sub_id<<'-'<<j.ti_to_sta<<' ';
//		}
//		cout<<endl;
//	}
	int xr,yr;
	for(int i=1;i<=q;i++){
		memset(fl,0,sizeof fl);
		cin>>xr>>yr;
		fl[xr]=1;
		dfs(xr,yr,0,-1);
		for(auto j : b[yr]){
			if(j.by_sub_id==lsub_id){
				ans_ti+=j.ti_to_sta;
				break;
			}
		}
		cout<<w[xr]+ans_ti+w[yr]<<endl;
		ans_ti=0;
	}
	return 0;
}
