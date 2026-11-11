#include <bits/stdc++.h>
using namespace std;
string luogu_name="tangzhuo";
/*
嗯。。。
我是不想写这一段话的； 
但是其它的题我是真的打不出来； 
这是我第2次打S； 
历史总是惊人的相似； 
我上次打S：
时间4h;
满分400分；
我拿了4分；
（很不吉利）
这次：
时间4h;
满分400分；
我估计可以拿4个点（大概率拿不到。。。）；
（很不吉利*2）

这题的0到底怎么处理呀！！！
废了；

我好难受呀。
明明付出了那么多的努力。
却还是那不到好的成绩。

“为什么这样子？”
“你拉着我手说你有些犹豫。”
“怎么这样子？”
“雨还没停你就撑伞要走。”
“我已经习惯不去阻止你，”
“过好一阵子你就会回来，”
“印象中的爱情好像顶不住那时间”
...
“所以我弃权！！！” 
*/
const int N=5*1e5+5;
long long n,m,a[N],d[N],ans,k=1;
bool flag=true,fla;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		if(a[i]==0&&i==1) {
			d[i]=a[i+1]-a[i];
			d[i-1]=d[i];
			fla=true;
		} else {
			d[i]=a[i]-a[i-1];
		}
		if(d[i]!=d[i-1]) {
			flag=false;
		}
		//cout<<d[i]<<' ';
	}
	//cout<<fla<<'\n';
	while(m>=0&&ans<=n) {
		if(m-a[k]>=0) {
			m-=a[k];
			ans++;
			k++;
			//cout<<m<<' '<<ans<<' '<<k<<'\n';
		} else {
			break;
		}
	}
	if(!fla) {
		ans++;
	}
	cout<<min(ans,n);
	return 0;
}
/*long long dp[5005][5005],n,m,a[N],maxn,p;

bool (int x,int y) {
	long long maxn=LLONG_MIN,sum=0;
	for(int i=x; i<=y; i++) {
		maxx=max(maxx,a[i]);
	}
	for(int i=x;i<=y;i++)
}

for(int t=2; t<=n; t++) {
	for(int i=1; i+t-1<=n; i++) {
		int j=i+t-1;
		if(dp[i][j-1]+dp)
		dp[i][j]=cha(i,j);
		if(cha(i,j)) {
			if(t>maxn) {
				maxn=t;
				continue;
			}
		}
	}
}
cout<<maxn;*/
