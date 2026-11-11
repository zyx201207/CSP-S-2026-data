//姓名：张邦寒  准考证号：SN-J00827 学校：西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200100];
string s[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ll maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		maxx=max(maxx,a[i]);
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(s[1]==s[2]){
			cout<<0;
		}else{
			cout<<min(a[1],a[2]);
		}
		return 0;
	}
	if(maxx==1){
		int lt=1,rt=n;
		ll ans=0;
		while(lt<rt){
			if(s[lt]!=s[rt]){
				ans++;
				lt++,rt--;
			}else{
				lt++,rt--;
			}
		}
		cout<<ans;
		return 0;
	}
	int l=1,r=n;
	ll ans=0;
	while(l<=r){
		if(s[l]==s[r]){
			if(a[l]==a[r]){
				l++,r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++,r--;
			}else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		} 
	}
	cout<<ans;
	return 0;
}
