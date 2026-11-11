#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int C,n,m,d,q;
int op[N],cnt[N];
struct Dis{
	int val;
	int st,ed;
}p[N][N];
struct node{
	int id;
	int time;
}s[N][N];
bool flag[N][N];
int main(){
	freopen("subway4.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>op[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];j++){
			int id,t;
			cin>>id>>t;
			s[i][id].time=t;
			flag[i][id]=true;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			p[i][j].val=1e9;
			for(int k=1;k<=n;k++){
				if(flag[k][i]&&flag[k][j]){
					if(p[i][j].val>s[k][i].time+s[k][j].time){
						p[i][j].st=p[i][j].ed=k;
						p[i][j].val=s[k][i].time+s[k][j].time;
					}
				}
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j&&i!=k&&j!=k){
					if(p[i][k].ed==p[k][j].st){
						if(p[i][k].val+p[k][j].val-s[p[i][k].ed][k].time-s[p[k][j].st][k].time<p[i][j].val){
							p[i][j].val=p[i][k].val+p[k][j].val-s[p[i][k].ed][k].time-s[p[k][j].st][k].time;
							p[i][j].st=p[i][k].st;
							p[i][j].st=p[k][j].ed;
						}
					}else{
						if(p[i][k].val+p[k][j].val<p[i][j].val){
							p[i][j].val=p[i][k].val+p[k][j].val;
							p[i][j].st=p[i][k].st;
							p[i][j].st=p[k][j].ed;
						}
					}
				}
			}
		}	
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		cout<<p[s][t].val+op[s]+op[t]<<'\n';
	}
	return 0;
}
