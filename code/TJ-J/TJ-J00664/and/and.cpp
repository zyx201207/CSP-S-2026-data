#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,m,num[200005],ans = 0,t[200005];
void pfs(int c,long long x){
	if(c == m + 1){
		ans = max(ans,x);
	}
	for(int i = 1;i <= n;i++){
		if(t[num[i]]) continue;
		t[num[i]] = 1;
		//cout<<x<<" "<<num[i]<<endl;
		if(c == 1) x = num[i];
		pfs(c + 1,x & num[i]);
		t[num[i]] = 0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>num[i];
	}
	if(pow(n,m) >= 1000000){
		sort(num + 1,num + n + 1);
		ans = num[n];
		for(int i = n - 1;i >= n - m;i--){
			ans &= num[i];
		}
		cout<<ans<<endl; 
	}
	else{
		pfs(1,num[1]);
		cout<<ans<<endl;
	}
	return 0;
}

