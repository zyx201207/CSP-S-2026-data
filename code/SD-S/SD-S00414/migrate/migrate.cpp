#include<bits/stdc++.h>
using namespace std;
#define int long long
int c;
int n,d,a[2000005];
int dcnt[5005];
int sol(int askl,int askr){
	if(askl>askr)return 0;
	int mn=3,ans=0;
	for(int i=askl+1;i<=askr;i++){
		dcnt[i]+=dcnt[i-1];
	}
	for(int i=askl;i<=askr;i++){
		if(dcnt[i]==2)ans++;
		mn=min(mn,dcnt[i]);
	}
	if(mn>2)return 0;
	
	int r=askr;
	for(int i=askl;i<=askr;i++){
		while(a[r]<=a[i]+d&&r<=n)r++;
		r--;
		dcnt[askr+1]+=dcnt[i];
		dcnt[r+1]-=dcnt[i];
	}
	dcnt[r+1]=0;
	return ans+sol(askr+1,r);
}
void solve(){
	int ans=0;
	cin >> n >> d;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++)dcnt[j]=0;
		int pos=i+1;
		while(a[pos]-a[i]<=d&&pos<=n)pos++;
		dcnt[i+1]=1;
		ans+=sol(i+1,pos-1);
	}
	cout << ans << "\n";
}
void sol1(){
	cin >> n >> d;
	for(int i=1;i<=n;i++)cin >> a[i];
	int pos=1;
	while(pos<=n&&a[pos]-a[1]<=d)pos++;
	pos-=2;
	if(pos<=1){
		cout << "0\n";return ;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int tt=i+pos+pos-1;
		if(tt>n)break;
		ans++;
	}
	cout << ans << "\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> c >> t;
	while(t--){
		if(c<=10)solve();
		else if(c<=12)sol1();
//		else sol2();
	}
	return 0;
}
