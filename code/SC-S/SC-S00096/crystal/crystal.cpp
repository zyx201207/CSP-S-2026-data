//小记：晚几秒钟发密码直接补5分钟。太好了。
//以下所有注释均在考试结束前书写
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e5+10;
ll n,m,a[maxn],b[maxn];
ll ans=0;

//Solve 1：这波贪了（贪心）
void solve1(){
	sort(a+1,a+1+n);//我寻思着没有顺序要求。
	ll cnts = 0,state=0;//记录操作次数与目前基准值。为什么这个m可以有1e18
//	while(cnts < m){//操作次数不多
//		if()
//	}
	
}


//解法2，暴力
ll sta,cnt;
//确保这个数不会再次成为基准，
//cnt：已用次数
void solve2(){
	sort(a+1,a+1+n);
	ll xuan=0;
	ll miss = -LONG_MAX;
	for(int i=1;i<=n;i++){
		sta = a[i];
		cnt = 0;
		xuan = 0;
		//cout << "State:" << sta << " now.\n";
		for(int j=i-1;j>=1;j--){
			if(cnt>=m) break;
			ll ned = sta-a[j];//如果选用该数字，则需要使用ned次魔法
			//如果选中i值时，剩余++次数足以与基准值相同，且差不为负（a[i]<=sta）
			if((cnt+ned)<=m && ned>=0){
				cnt+=(sta-a[j]);
				xuan++;
			}
		}
		//cout << "Done." << xuan << "\n";
		miss = max(miss,xuan);
	}
	ans = miss+1;
}

//不可触碰：输出1，也就是只有他自己能成为大宝石。
void solveX(){
	ans = 1;
}

int main(){
	//重要福瑞open（请检查文件名是否对应）
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//解绑输入输出恋人关系(禁用scanf和printf)
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	//输入n,m
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	solve2();
	cout << ans;
	//关闭福瑞open重定向
	fclose(stdin);
	fclose(stdout);
	return 0;
}