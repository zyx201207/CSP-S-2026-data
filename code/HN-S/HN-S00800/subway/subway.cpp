#include<bits/stdc++.h>
using namespace std;
const int MAX_M = 5e5+5,MAX_N=505;
int c,n,m,d,q,x,y,o;
int k[MAX_N],jia[MAX_N],cha[MAX_N],chb[MAX_N],ans=0xff;
int w[MAX_M];
int ma[MAX_N][MAX_N];
map<int,int> t[MAX_N],to[MAX_N];
queue<int> whi[MAX_M],l,u;
void add(int i){
	l = whi[i];
	int j=1;
	while(!l.empty()){
		jia[j]=l.front();
		l.pop();
		j++;
	}
//	cout<<j<<"\n";//
	for(int r=1;r<=whi[i].size()-1;r++){
		for(int e=r;e<=whi[i].size();e++){
			if(r!=e){
//				cout<<jia[r]<<" "<<jia[e]<<" "<<e<<"\n";//
				if(ma[jia[r]][jia[e]]!=0)ma[jia[r]][jia[e]]=ma[jia[e]][jia[r]]=min(t[jia[r]][to[jia[r]][i]]+t[jia[e]][to[jia[e]][i]],ma[r][jia[e]]);
				else ma[jia[e]][jia[r]]=ma[jia[r]][jia[e]]=t[jia[r]][to[jia[r]][i]]+t[jia[e]][to[jia[e]][i]];
//				cout<<t[jia[r]][to[jia[r]][i]]+t[jia[e]][to[jia[e]][i]]<<" "<<ma[r][jia[e]]<<"\n";//
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ma,0,sizeof(ma));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>o>>t[i][j];
			to[i][o]=j;
			whi[o].push(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(whi[i].size()!=1){
			add(i);
		}
	}
	for(int j=1;j<=n-1;j++){
		for(int p=j+1;p<=n;p++){
			for(int i=1;i<=n;i++){
				if(i!=j&&i!=p){
					ma[p][j]=ma[j][p]=min(ma[i][j]+ma[i][p],ma[j][p]);
//					cout<<j<<" "<<i<<" "<<p<<" "<<ma[j][p]<<"\n";//
				}
			}
		}
	}
	while(q--){
		ans = 0xff;
		cin>>x>>y;
//		cout<<whi[x].front()<<" "<<ma[whi[x].front()][whi[y].front()]<<" "<<whi[y].front()<<"\n";//
		if(whi[x].size()==1&&whi[y].size()==1)cout<<ma[whi[x].front()][whi[y].front()]+t[whi[x].front()][to[whi[x].front()][x]]+t[whi[y].front()][to[whi[y].front()][y]]+w[x]+w[y]<<"\n";
		else{
			l = whi[x];
			u = whi[y];
			int j=1;
			while(!l.empty()){
				cha[j]=l.front();
				l.pop();
				j++;
			}
			j=1;
			while(!u.empty()){
				chb[j]=u.front();
				u.pop();
				j++;
			}
			for(int r=1;r<=whi[x].size();r++){
				for(int e=1;e<=whi[y].size();e++){
					if(cha[r]!=chb[e])ans=min(ma[cha[r]][chb[e]]+t[cha[r]][to[cha[r]][x]]+t[chb[e]][to[chb[e]][y]],ans);
					else ans=min(t[cha[r]][to[cha[r]][x]]+t[chb[e]][to[chb[e]][y]],ans);
//					cout<<cha[r]<<" "<<chb[e]<<" "<<ans<<"\n";//
				}
			}
			cout<<ans+w[x]+w[y]<<"\n";
		}
	} 
	return 0;
}
