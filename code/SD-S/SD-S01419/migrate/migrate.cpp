#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+7;
int T,c,n,a[N],d,ans=0;
set<int> s;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		s.clear();
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i],s.insert(a[i]);
		if(c==11||c==12){
			if(2*(a[1]-a[0])<=d&&d<3*(a[1]-a[0]))cout<<n-3<<'\n';
			else cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int cnt=0;
				for(int k=i;a[k]-a[i]<=d&&k<=j;k++){
					if(a[j]-a[k]>d)continue;
					if(s.count(a[i]+a[j]-a[k]))cnt++;
					if(cnt>=3)break;
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*

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


