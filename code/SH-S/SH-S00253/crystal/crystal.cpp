#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,ans,n,a[500010];
bool check1(){
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++)
		if(a[i] != i)return 0;
	return 1;
}
bool check2(){
	sort(a + 1,a + 1 + n);
	int dist = a[2] - a[1];
	for(int i = 2;i < n;i++)
		if(a[i + 1] - a[i] != dist)return 0;
	return 1;
}
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	if(check1()){
		int cnt = 0,k = 0;
		for(int i = 1;i <= n;i++,k++){
			cnt += i;
			if(cnt > m)break;
		}
		cout<<++k;
	}
	else if(check2()){
		int cnt = 0,k = 0,dist = a[2] - a[1];
		for(int i = dist;k <= n;i += dist,k++){
			cnt += i;
			if(cnt > m)break;
		}
		cout<<++k;
	}
	else{
		sort(a + 1,a + 1 + n);
		for(int i = 1;i <= n;i++){
			ll pvt = a[i],cnt = 0,k = 1;
			for(int j = i - 1;j >= 1;j--){
				if(cnt > m)break;
				cnt += (pvt - a[j]);k++;
				if(cnt > m)k--;
			}
			ans = max(ans,k);
		}
		cout<<ans;
	}
	return 0;
}
