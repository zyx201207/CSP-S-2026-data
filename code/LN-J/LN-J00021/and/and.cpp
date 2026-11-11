#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int q[32],cnt[32];
int a[N],n,m,ans,maxn;

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.ont","w",stdout);
	cin >> n >> m;
	q[0] = 1;
	for(int i = 1;i <= 30;i++){
		q[i] = q[i-1]*2;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		for(int j = 1;j <= 30;j++){
			if(a[i] < q[j]){
				cnt[i]++;
				break;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	if(m == 1){
		cout << a[1];
	}
	else if(m == 2){
		maxn = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if((a[i] & a[j]) >= maxn){
					maxn = (a[i] & a[j]);
				}
			}
		}
		cout << maxn;
	}else if(m == n){
		ans = a[1];
		for(int j = 2;j <= m;j++){
			ans &= a[j];
		}
		cout << ans;
	}else if(m == n-1){
		ans = a[1];
		for(int j = 2;j <= m;j++){
			ans &= a[j];
		}
		maxn = 0;
		for(int i = 1;i <= n;i++){
			if((ans ^ a[i]) >= maxn){
				maxn = (ans^a[i]);
			}
		}
		cout << maxn;
	}
	//for(int i = 30;i >= 1;i--)
	//{
		//if(cnt[i] >= m){
			//int ans = a[1];
			//for(int j = 2;j <= m;j++){
				//ans &= a[i];
			//}
			//cout << ans;
			//return 0;
		//}
		//else{
			//for(int j = 1;j <= n;j++){
				//if(a[j] >= q[i-1]){
					//a[j] = a[j]-q[i-1];
				//}
				//else{
					//break;
				//}
			//}
			//sort(a+1,a+n+1,cmp);
		//}		
	//}
	return 0;
}
