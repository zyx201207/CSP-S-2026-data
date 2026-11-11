#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;

LL n, m;
LL a[600005], b[600005];
bool cmp(LL x, LL y){
	return x < y;
}
LL ans, cans;
int main(){
	freopen("E:\\NOI\\crystal.in","r",stdin);
	freopen("E:\\NOI\\crystal.out","w",stdout);
	cin >> n >> m;
	
	for(int i= 1; i <= n; i++){
		cin >> a[i];
		
	}
	sort(a+1, a+n+1, cmp);
	LL l = 0,lastn = 0, mm = m;
	for(LL i = 2; i <= n; i++){
		cans = m/(i-1-l);
		while(i > l+1 && cans < a[i]-a[i-1]){
			l++;
			m+=a[i-1];
			
			cans=m/(i-l);
		}
		if(i == l+1 && cans < a[i]-a[l]){
			m = mm;
		}
		else{
			for(LL j = i-1; j > l; j--){
				m -= a[i]-a[i-1];
			}
		}
		//cout << i << l << i-l << endl;
		ans = max(i-l,ans);
		//cout << ans << endl;
	}
	
	
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
