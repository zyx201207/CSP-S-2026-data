#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
void solve1(){
	int d=a[2]-a[1];
	int diff=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(m>=diff){
			m-=diff;
			cnt++;
			diff+=d;
		}
	}
	cout<<cnt;
	return ;
} 
void solve_brute(){
	int mx=1;
	for(int i=n;i>=1;i--){
		int rem=m,cnt=0;
		for(int j=i;j>=1;j--){
			if(rem>=(a[i]-a[j])){
				rem-=(a[i]-a[j]);
				cnt++;
			}
			else break; 
		}
		mx=max(mx,cnt);
//		cout<<cnt<<" ";
	}
	cout<<mx;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool f=1;
	for(int i=1;i<=n;i++){
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			f=0;
		}
	} 
	if(f==1){
		solve1();
		return 0;
	}
	if(n<=5000){
		solve_brute();
		return 0; 
	}
	int pos=n,rem=m;
	int mx=1;
	for(int i=n;i>=1;i--){
		if(i!=n)rem+=(i-pos)*(a[i+1]-a[i]);
//		cout<<i<<" rem="<<rem<<" pos=";
		pos=min(pos,i);
		while(pos>=1&&rem>=a[i]-a[pos]){
			rem-=a[i]-a[pos];
//			cout<<a[i]-a[pos]<<" rem="<<rem<<"\n";
			pos--;
		}
//		cout<<pos<<" -> rem="<<rem<<"\n";
		mx=max(mx,i-pos);
//		if(i==5)break;
//		cout<<i-pos+1<<" "; 
	}
	cout<<mx;
	return 0;
}
/*
6 6
1 10 11 12 13 100
*/

