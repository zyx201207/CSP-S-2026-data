#include<fstream>
#include<vector>
using namespace std;
#define int long long
int c,n,m,d,q,k,x,y;
struct st{int m,t;};
signed main(){
	ifstream fin("subway.in");ofstream fout("subway.out");//换用fstream后变成了1018ms，我无疑是/fn的
	//1046ms，还得卡常！？/fn
	//既然都用fstream了，那就用//freopen诈骗一下看这些代码的人吧（
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	fin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	vector<vector<int> > dis(m+1,vector<int>(m+1,(int)5e9));
	for(int i=1;i<=m;i++)
		fin>>w[i],dis[i][i]=0;
	vector<st> tmp;
	for(int i=0;i<n;i++){
		fin>>k;
		tmp.resize(k);
		for(int i=0;i<k;i++)
			fin>>tmp[i].m>>tmp[i].t;
		for(int i=0;i<k-1;i++)
			for(int j=i+1;j<k;j++)
				dis[tmp[i].m][tmp[j].m]=min(dis[tmp[i].m][tmp[j].m],tmp[i].t+tmp[j].t),
				dis[tmp[j].m][tmp[i].m]=dis[tmp[i].m][tmp[j].m];
	}                                                                                      
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	//神秘的Floyd（为什么我会想到这个），还好我中午严肃询问了大神@lmaz，又骗到一些分（喜）
	while(q--){
		fin>>x>>y;
		fout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
}
//关注pigoen4836谢谢喵

//ccf please give me 100pts