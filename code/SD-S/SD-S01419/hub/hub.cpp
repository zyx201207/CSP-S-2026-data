#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,dip[1000005],cnt=0,mx=1;
vector<int> e[1000005];
queue<int> q;
void dfs(int u,int fa){
	dip[u]=dip[fa]+1;
	for(int v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dip[1]=1;
		dfs(1,0);
		for(int i=2;i<=n;i++)if(dip[i]>dip[mx])mx=i;
		dip[mx]=1;
		dfs(mx,0);
		for(int i=1;i<=n;i++)mx=max(mx,dip[i]);
		cout<<(mx-2*k+2)/3<<'\n';
	}
	return 0;
}
/*

md zuo bu wan le wo cao si feng tu lun

luogu user 667452 hu guan pls

<shi mo ge zhe>

wo yi ran zai wu ren wen jin de yin yu mei shi zhi di
he zhe yu yin chang zhe mei you ting zhong de ge qu
ren chao reng shi man wu mu di de xiang mu di di san qu
mang lu zhe wu wei zhe ji xu

qi qiu zhe shui neng gou jiang wo de xin fang qing qing kou ji
ji shi shi ni ye jin jin zhu zu le pian ke bian li qu
xiang zhe huo xu xia ge lu kou hui you shui yu wo xiang yu
na pa zhi yi shun de qi ji

<dong jing bu tai re>

ding ding dang dang QQ xiang qi hui shi shui ne Nayo
hui shi ta ma Nayo
shen me shi ne Ayo

jia zhuang zheng jing bang ta ba shi qing dou bai ping Nayo
bu duo liao le Nayo
qu chi fan le Ayo

xin li ming ming hen xi huan que bao chi zhe ju li
o pa bei shang hai jiu wei zhuang chu gao leng de biao qing
yi wei zhe yang zong you yi tian ta hui jie jin ni
zhi dao na tian kan jian ta he bie ren zai yi qi

*/


