#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int f[N];
int cnt[N];
bool flag;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&a[i]>=a[i+1]){
        	flag=1;
		}
    }
    if(n>5000){
	    if(!flag){
			for(int i=1;i<=n;i++){
		        cnt[a[i]]=i;
		    }
		    for(int i=1;i<=m;i++){
		    	cout<<cnt[i]<<" ";
			}
			return 0;
		}
		if(m<=2){
			cnt[a[n]]=n;
			for(int i=1;i<=n;i++){
				if(a[i]!=a[n]){
					cnt[a[i]]++;
				}
			}
		    for(int i=1;i<=m;i++){
		    	cout<<cnt[i]<<" ";
			}
			return 0;
		}
	}
    for(int i=1;i<=n;i++){
    	stack<int>st;
        for(int j=i;j<=n;j++){
            if(f[a[j]]){
            	while(!st.empty()){
            		int w=st.top();
            		st.pop();
            		f[w]--;
            		if(w==a[j])break;
				}
			}
			st.push(a[j]);
			f[a[j]]++;
        }
        for(int j=1;j<=m;j++){
        	cnt[j]+=f[j];
        	f[j]=0;
		}
    }
    for(int i=1;i<=m;i++){
    	if(i==m) cout<<cnt[i];
    	else cout<<cnt[i]<<" ";
	}
    return 0;
}
/* 
bu hui le miao.
zhu ge wei RP++ miao.
wo de T2 mao si guo bu qv miao.
T4 mei you si lu miao miao miao.
xian zai cai 9:49 wo jiu bu hui le miao miao miao miao miao.
wo neng yi deng ma miao miao miao.
wo ben neng xie tai duo le fou ze hui chao chu 100 Kib.
er qie hui shang mi huo xing wei da shang miao.
wo yao zha pian
(zhe li ben lai you 100 ge //freopen bei wo shan le)
T4 shi hong ma? shi cheng ma? shi huang ma?shi lv ma?shi qing ma?shi lan ma?shi zi ma?shi hei ma?
wo ren wei da an shi 000???00(0 biao shi no,?biao shi ke neng)
9:55 le,wo hai you yi kou shui,neng huo ma?
qing wen hou lai ren zhi dao zhe shi DP ma?
wo jue de bu xiang miao.you hou xiao xing miao.
bu ke yi DP ba.wo zhi neng xiang chu lai dang qian shi di i jv you xi he zhuo mian shang de pai liang ge zhuang tai.
liang ge tong shi ji lu hui bao.zhi ji lu qi zhong de yi ge ye mei fa zhuan yi
bu shi DP,ye bu neng bao li.
he tu che shang guan xi de ye jiu zhi ke neng shi xiang xia yi ge he zhe ge wei zhi de zhi yi yang de jie dian le.
bu guo wo lian le,hai shi bu hui zhuan yi miao.
suo yi dao di shi shen me a.
shi jian dou guo qv le yi ge xiao shi le hai shi mei you si lu,zai ping yi xie fen shu ba.
zheng de ke yi 100+100+100+60 ma ,wo jue de hui gua fen miao miao miao
hai shi mei you AK miao
shi bai le miao

*/