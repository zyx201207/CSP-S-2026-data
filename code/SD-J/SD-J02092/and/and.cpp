#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005]={0};
int ma=0;
int n,m;
void bf(int now,int sum,int s){
	if(s==m){
		//cout << sum << " " << s <<  endl;
		ma=max(ma,sum);
		return;
	}
	for(int i=now;i<n;i++){
		//cout << a[i] << " ";
		if(sum!=0){
			bf(i+1,sum&a[i],s+1);
		}else{
			bf(i+1,a[i],s+1);
		}
	}
	//cout << endl;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0;i<n;i++)cin >> a[i];
	if(m==n){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout << ans << endl;
		return 0;
	}
	if(m==1){
		sort(a,a+n);
		cout << a[n-1] << endl;
	}else{
		for(int i=0;i<n-m;i++){
			bf(i,0,0);
		}
		cout << ma << endl;
	}
	return 0;
}
