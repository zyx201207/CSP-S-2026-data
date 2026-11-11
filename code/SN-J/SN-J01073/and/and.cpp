#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],b[200010],fl = 1,f2 = 1;
long long ans;
bool cmp(int a,int b){
	return a > b;
}
//b为前缀与数组 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[0] = a[1];
		b[i] = a[i] & b[i - 1];
		if(a[i] >= 4)fl = 0;
		if(a[i] != i - 1)f2 = 0;
	}//不选x则其余与的和为1.x在首=b[n]&b[x]2.在尾=b[x - 1]3.中间=b[n] & b[x-1] 
	//cout << b[n] << "&" << b[2] << "==" << int(b[n] & b[1]);
	if(fl){//16~17
		sort(a + 1,a + n + 1,cmp);
		ans = a[1];
		for(int i = 1;i <= m;i++)ans &= a[i];
		//cout << ans;
	}
	else if(m == 1){//6
		for(int i = 1;i <= n;i++)ans = max(ans,a[i]);
	}
	else if(m == 2){//8~10
		int x = 0;
		for(int i = 1;i <= n;i++)for(int j = i + 1;j <= n;j++){
			ans = max(a[j] & a[i],ans);
		}
	}
	else if(f2){//14~15
		sort(a + 1,a + n + 1,cmp);
		if(m < n){
			ans = a[2];
			for(int i = 2;i <= m;i++)ans &= a[i];
		}
		else {
			ans = a[1];
			for(int i = 1;i <= m;i++)ans &= a[i];
		}
	}
	else if(m == n){//7
		ans = a[1];
		for(int i = 1;i <= n;i++)ans &= a[i];
	}
	else if(m == n - 1){//11~12
		for(int i = 1;i <= n;i++){
			if(i == 1)ans = max(ans,b[n] & b[1]);
			else if(i == n)ans = max(ans,b[n - 1]);
			else ans = max(ans,b[i - 1]&b[n]);
		}
	}
	else if(n <= 20){//1~5
		if(m == 2)for(int i = 1;i <= n;i++)for(int j = i + 1;j <= n;j++)ans = max(ans,a[i] & a[j]);
		if(m == 3)for(int i = 1;i <= n;i++)for(int j = i + 1;j <= n;j++)for(int k = j + 1;k <=n;k++)ans = max(ans,a[i] & a[j] & a[k]);
		if(m == 4)for(int i = 1;i <= n;i++)for(int j = i + 1;j <= n;j++)for(int k = j + 1;k <=n;k++)for(int l = k + 1;l <= n;l++)ans = max(ans,a[i] & a[j] & a[k] & a[l]);
	}
	else {//13
		sort(a + 1,a + n + 1,cmp);
		if(m < n){
			ans = a[2];
			for(int i = 2;i <= m;i++)ans &= a[i];
		}
		else {
			ans = a[1];
			for(int i = 1;i <= m;i++)ans &= a[i];
		}
	}
	cout << ans;
}
