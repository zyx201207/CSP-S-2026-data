#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,m,a[N],b[N];
bool check(int x){
	for(int i=x+1;i<=n;i++)if(b[i]-b[i-x]-(a[i]-a[i-x])*(i-x-1)<=m)return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
//	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	int l=0,r=n-1;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l+1<<'\n';
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

