#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N= 2e5 +100;
const int LOG = 31;
int a[N]; 
int ans = -1;
void dfs(int x,int n,int val,int m,int cnt){
	//cout << x << ' ' << n <<' ' << val << ' ' << m << ' ' <<cnt << '\n';
	//剪枝
	if(val <= ans) return ; //最优性剪枝
	if(n-x+1 + cnt < m) return ;//如果选不玩,那还选啥 
	//选完了
	if(cnt == m){
		ans = val;
		return ;
	}
	//选
	dfs(x+1,n,val&a[x],m,cnt+1);
	//不选 
	dfs(x+1,n,val,m,cnt);
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//and
	//看我拿部分分拿到75 可能85 
	srand(time(0));
	bool A = true;
	bool B = true;
	bool C = true;
	int n,m; cin >>n >>m;
	for(int i = 1; i <= n; i++){
		cin >>a[i];
		//判A
		for(int j = LOG; j > 0; j--)
			if(((a[i] >> j) & 1) &&!((a[i] >> j-1) & 1))
				A = false;
		//判B
		if(a[i] != i-1) B = false; 
	}
 	if(n <= 20){//可以暴力
		dfs(1,n,(1 << LOG) - 1,m,0);
		cout <<ans;
		return 0;
	}else if(m == 1){//选最大的
		int mx = -10086 - 114514 - 9178;
		for(int i = 1; i <= n; i++)
			mx = max(mx,a[i]);
		cout << mx;
		return 0; 
	}else if(m == n){//只能全选 
		int ans = (1<<LOG)-1;
		for(int i = 1; i <= n; i++)
			ans &= a[i];
		cout <<ans;
		return 0;
	}else if(m == 2){//暴力选两个 
		int ans = -1;
		for(int i = 1; i <= n; i++)
			for(int j = i+1; j <= n; j++)
				ans = max(ans,a[i]&a[j]);
		cout <<ans;
		return 0;
	}else if(m == n-1){//枚举哪一个不选
		int ans = -1;
		for(int i = 1; i <= n; i++){
			int sum = (1 << LOG) - 1;
			for(int j = 1; j <= n; j++){
				if(j == i) continue;
				sum &= a[j];
			}
			ans = max(ans,sum);
		}
		cout <<ans;
		return 0;
	}else if(A){//满足性质A
		//选最大的m个
		sort(a+1,a+n+1);
		int ans = (1 <<LOG)-1;
		for(int i = n; i > n-m; i--)
			ans &= a[i];
		cout << ans;
		return 0; 
	}else if(B){//满足性质B	 
		//选最大的m个(没证明)
		int ans = (1 <<LOG)-1;
		for(int i = n; i > n-m; i--) 
			ans &= a[i];
		cout << ans;
		return 0; 
	}else if(C){//满足性质C (ai <= 4) 
		int cnt1,cnt2,cnt3,cnt4;
		for(int i = 1; i <= n; i++){
			if(a[i]==1)cnt1++;
			if(a[i]==2)cnt2++;
			if(a[i]==3)cnt3++;
			if(a[i]==4)cnt4++;
		}
		if(cnt4>=m) cout << 4;
		else if(cnt3>=m) cout <<3;
		else if(cnt2>=m || cnt2+cnt3 >= m) cout <<2;
		else if(cnt1>=m || cnt1+cnt3 >= m) cout << 1;
		else cout <<0;
		return 0;
	}else{
		//反正做不出来
		cout << rand(); 
	}
}
