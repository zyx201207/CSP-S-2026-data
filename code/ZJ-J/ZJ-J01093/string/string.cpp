#include<bits/stdc++.h>
#define fri freopen("string.in","r",stdin)
#define fro freopen("string.out","w",stdout)
#define con const int
#define endl '\n'
#define intl long long
using namespace std;
con N=2e5+5;
int a[N];
string s[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	intl sum,ans=0;
	sum=a[1];
	bool vis=0;
	for(int l=1,r=n;l!=r;){
		if(s[l]!=s[r]){
			if(vis==0){
				if(sum>=a[r]){
					ans+=a[r];
					sum-=a[r];
					r--;
				}
				else{
					ans+=sum;
					sum=a[r]-sum;
					l++;
					vis=1;
				}
			}
			else{
				if(sum>=a[l]){
					ans+=a[l];
					sum-=a[l];
					l++;
				}
				else{
					ans+=sum;
					sum=a[l]-sum;
					r--;
					vis=0;
				}
			}
		}
		else{
			if(vis==0){
				if(sum>=a[r]){
					sum-=a[r];
					r--;
				}
				else{
					sum=a[r]-sum;
					l++;
					vis=1;
				}
			}
			else{
				if(sum>=a[l]){
					sum-=a[l];
					l++;
				}
				else{
					sum=a[l]-sum;
					r--;
					vis=0;
				}
			}
		}
	}
	cout<<ans;
}
int main(){
	fri;fro;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}

