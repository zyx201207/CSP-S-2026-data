#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5+10;
int n,m,a[N],b[N],max_ = -1,tmp;bool flag = true;
int dfs(int i,int now,int step){
	if(step == m){
		return now;
	}
	int max_ = -1;
	for(int j = i+1;j <= n - m + step + 1;j++){
		max_ = max(max_,dfs(j,now & a[j],step+1));
	}
	return max_;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(~a[i]) flag = false;
	}
	sort(a+1,a+n+1,greater<int>());
	if(m == 1){cout << a[1];
	}else if(flag){cout <<a[m];
	}else{
		for(int i = 1;i <= n - m + 1;i++){
			max_ = max(dfs(i,a[i],1),max_);
		}
		cout << max_;
	}
	return 0;
}
