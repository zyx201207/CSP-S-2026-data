#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5000;
int c,t;
int n,k;
vector<int>v[N];
bool f[N];
int fa[N],d[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(c<=3){
			int minn=1e18;
			for(int i=0;i<(1ll<<n);i++){
				int ans=0;
				for(int j=1;j<=n;j++){
					if((((i>>(j-1))&1)==1))f[j]=1;
					else f[j]=0;
					if(f[j])ans++;
					fa[j]=j;
					d[j]=1e18;
				}
				if(ans!=k)continue;
				for(int j=1;j<=n;j++){
					if(f[j]==0)continue;
					for(int k=0;k<v[j].size();k++){
						if(f[v[j][k]]==0)continue;
						fa[find(j)]=find(v[j][k]);
					}
				}
				ans=0;
				queue<int>q;
				for(int j=1;j<=n;j++){
					if(!f[j])continue;
					if(fa[j]==j)ans++;
					d[j]=0;
					q.push(j);
				}
				if(ans>2)continue;
				while(!q.empty()){
					int x=q.front();
					q.pop();
					for(int j=0;j<v[x].size();j++){
						int w=v[x][j];
						if(d[w]>d[x]+1){
							d[w]=d[x]+1;
							q.push(w);
						}
					}
				}
				ans=0;
				for(int j=1;j<=n;j++){
					ans=max(ans,d[j]);
				}
				minn=min(ans,minn);
			}
			cout<<minn<<"\n";
		}
	}
	return 0;
}
/*
miao miao wo you hui lai le.wo shi ZJ-J00532.
suo yi J zu T4 wo hai shi bu hui miao.wo xian zai you dian huang.
ying wei wo mao si ba J zu T4 de dai ma shan le.
zhe yi chang ye shi shen mi de guo le T2 de da yang li.
xian zai shi 15:39 miao,ben lai xiang da T2 de bao li pian zou 60 fen.
xian zai wo da le,ke shi mei guo yang li miao.
shang xin,suo yi zhi neng huan le yi ge suan fa miao.
T2 yan li dao xian zai hai shi mei you du dong ne miao.zen me jiu guo le da yang li miao.
xi wang you hou lai ren bang wo jie shi yi xia miao.
hua shuo wo zhen de you 200 fen ma?wo wen wo zi ji.
wo neng xie chu T3 you bao li fen 40 miao.
16:02 T3 bao li xie hao le miao,wo yao xie te shu xing zhi le miao.
16:16 xing zhi A xie hao le miao.
wo zai 16:20 fa xian le xing zhi B wo bu hui miao .
xing zhi C mao si geng nan zuo tiao le .
shui bu duo le miao hai you zheng zheng 2 ge xiao shi miao.
ru he zai liang ge xiao shi nei zhi he diao san kou shui miao.
bu gua fen yi jing you le ?+?+? le miao.
(zhu:zhe li ben lai you san ge fen shu,dan shi bei wo na zou le miao).
T4 zui da zhi zui xiao,shi er fen miao,ke shi bu hui miao.
xing zhi A shuo ming shi zai 1~m zhong fang zhi.
xiang le yi xia zhi hui 15 fen miao.
mao si ke yi guo miao.
bu neng xie tai chang le yao de 0 fen de miao.
li kao shi jie shu hai you 2 xiao shi miao.gou wo zuo de le miao.
hui ba wo fang shang mi huo xing wei da shang ma.
hao xiang hui de,suo yi miao miao miao.
miao miao miao miao.
wei shen me you ren wen di tie shi fou shi dan xiang tong xing?
wei shen me you ren wen niao shi bu shi dan xiang fei xing?
T3 bu shi xie cheng dan xiang geng fang bian ma?
miao miao miao bu hui le kai shi jian cha zai 16:49.
zhu:wo de zhe xie  dou shi zai sai shi xie de,dao shen me cheng du jiu xie le shen me.
gei zhe chang bi sai de nan du ping jia shi:cheng/huang lv/qing/lan lan/zi/hei zi/hei .
T1kan shang qv jiu shi zhe ge miao,ni ke yi yong er fen/shuang zhi zhen qv zuo.
T2dui wo lai shuo jiu shi du ti tai nan le,qi ci yang li jie shi jia le ge kuo hao miao.
zhe ge n de fan wei jiu zhi ying zhe wo men xie Floyd,dan shi ru guo ni mei you du dong ti.
mu ni jiu kan bu chu lai miao.
T3,T4 wo zuo bu chu lai miao,ping jia li you jiu shi geng jv wang nian lai kande miao.
jin nian fen shu xian hui bu hui heng gao miao?
fen shu xian gu ji hui bi jiao gao miao.
bi jing xiao wo zhe yang cai de miao dou zuo chu lai le miao.
wei le cou dao 4000 shan diao le yi xie zi fu.
suan le zai cou ge 1000 zi bu ran tai wu liao le.
xian zai shi 17:38,wai mian tian yi jing hei le.
wo xian zai bu zhi dao yao gan shen me miao miao miao.
wo chang chang zhui yi guo qv.
zhong jian wang le.
wo gai ting liu zai na li?wo wen wo zi ji.
wo de zhu shi yi jing bi dai ma yao chang le.
huo shuo J zu de nan du shi bu shi hong cheng cheng lv/qing/lan a.
wei shen me wo zuo bu chu J zu T4,wo dui J zu T4 yi dian tou xv dou mei you.
xian zai you you ke neng bei shan le,yi deng gu ji mei you le miao miao miao(sad)
suo yi J zu de T4 dao di shi shen me suan fa?bu shi DP miao ,ye bu shi tu lun ba miao?
na hai you shen me fang mian de zhi shi dian ne?wo xiang bu chu lai le.
hai you zhe ci de T3 wo jue de shi tu lun.ke shi wo bu hui miao.
T4 you shi shen me zuo fa ne?wo jue de wo de fen shu ying gai you yi deng le.
xie le zhe me duo hui shang mi hui xing wei da shang ma miao. 
xi wang bu yao a miao miao miao.wo bu xi wang shang a miao.
miao miao miao miao miao miao miao miao miao.

*/