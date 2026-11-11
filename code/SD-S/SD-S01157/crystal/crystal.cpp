#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001000],s[1001000],ans,cnt,yx,sum,u,k,mk;
bool cmp(int a,int b){
	return a < b;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n;i ++){
		s[i] = a[i];
		a[i] -= s[i - 1];
		if(i != 1 && a[i] != 0){
			u ++;
		}
		if(i >= 3 && a[i] != a[i - 1]){
			k ++;
		}
		mk = a[i];
	}
	if(u == 0){
		cout<<n;
		return 0; 
	}
	if(k == 0){
		int u = 0;
		for(int i = 1;i <= n;i ++){
			u += mk;
			if(u > m){
				cout<<i - 1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	for(long long i = n,j = n;;){
		if(i == 0ll){
			break;
		}
		if(j != 0ll && yx + (s[i] - s[j]) <= m){
			yx += (s[i] - s[j]);
			j --;
			sum ++;
			ans = max(ans,sum);
		}else{
			yx -= a[i] * (sum - 1);
			i --; 
			sum --;
		}
	}
	cout<<ans;
	return 0;
}
//¼Ólonglong
//É¾×¢ÊÍ 
//É¾ÎÄ¼þ 
//jyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjyjy
