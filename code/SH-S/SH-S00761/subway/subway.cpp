//1
#include<bits/stdc++.h>
using namespace std;
const int MAXN=550,MAXM=500500;
int c,n,m,d,q,k,ans;
vector<int> w;
vector<vector<int> > a;
vector <vector<int > > con;
vector<vector<int> > has;
int s[MAXN][MAXN],t[MAXN][MAXM];
bool f[MAXN];
struct para{
	int len;
	int s;
};
int p[MAXN];
// 6767
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
priority_queue <pair<int,int> > sea;
int main(){
	
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	memset(t,-1,sizeof(t));
	a.assign(n+5,vector<int>());
	con.assign(n+5,vector<int>());
	has.assign(m+5,vector<int>());
	w.push_back(-1);
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		w.push_back(x);
	}
	for(int i=1;i<n+1;i++){
		cin>>k;
		for(int abc=0;abc<k;abc++){
			int x;
			int y;
			cin>>x;
			cin>>y;
			a[i].push_back(x);
			t[i][x]=y; 
			for(auto &pa:has[x]){
				con[i].push_back(pa);
				s[i][pa]=(s[i][pa]!=0?min(t[i][x]+t[pa][x],s[i][pa]):t[i][x]+t[pa][x]);
				s[pa][i]=s[i][pa];
			}
			has[x].push_back(i);
		} 
	} 
	for(int b=0;b<q;b++){
		int x;
		int y;
		cin>>x>>y;
		ans=-1;
		memset(f,0,sizeof(f));
		for(auto &i:has[x]){
			sea.push({t[i][x],i});
			f[i]=1;
		}
		for(auto &j:has[y]){
			sea.push({t[j][y],j});
			f[j]=1;	
		} 
		while(!sea.empty()){
			pair<int,int> temp=sea.top();
			sea.pop();
			int len=temp.first;
			int side=temp.second;
			p[side]=len;
			if(t[side][x]>0&&t[side][y]>0){
				ans=t[side][x]+t[side][y];
				break;
			}
			for(auto &i:con[side]){
				if(f[i]){
					ans=(ans>0?min(ans,p[side]+p[i]+s[side][i]):p[side]+p[i]+s[side][i]);
				}
				else{
					sea.push({len+s[side][i],i});
				}
			}
			f[side]=1;
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
}
//?
