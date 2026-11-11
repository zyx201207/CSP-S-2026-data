#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
void solve(){
	int ans=0;
	if(n<=20){
		for(int state=0;state<=(1<<n);state++){
			int sum=0,cnt=0;
			for(int i=0;i<=20;i++){
				if(state&(1<<i)){
					cnt++;
					if(sum!=0){
						sum&=a[i];
					}
					else{
						sum=a[i];
					}
				}
			}
			if(cnt==m)ans=max(ans,sum);
		}
	}
	else{
		if(m==1){
			for(int i=0;i<n;i++)ans=max(ans,a[i]);
		}
		else if(m==2){
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		else if(m==n){
			int sum=a[0];
			for(int i=0;i<n;i++)sum&=a[i];
			ans=sum;
		}
	}
	cout << ans;
	return;
}
void solve1(){
	int ans=0;
	for(int i=0;i<n;i++){
		int sum=a[0];
		for(int j=1;j<i;j++){
			sum&=a[j];
		}
		for(int j=i+1;j<n;j++){
			sum&=a[j];
		}
		ans=max(ans,sum);
	}
	cout << ans;
	return;
}
void solve2(){
	sort(a,a+n,greater<int>());
	int ans=a[0];
	for(int i=1;i<m;i++){
		ans&=a[i];
	}
	cout << ans;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++)cin >> a[i];
	if(n<=2000)solve();
	else if(m==n-1)solve1();
	else solve2();
	
	return 0;
} 
