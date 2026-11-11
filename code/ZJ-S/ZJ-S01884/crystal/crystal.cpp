#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int st=0;
int a[N];
int cf[N];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int st=n;st>1;--st){
		int cnt=1;
		for(int i=1;i<st;++i){
			cf[i]=a[st]-a[i];
		}
		int rt=m;
		for(int i=st-1;i>=1;--i){
			if(rt>=cf[i]){
				rt-=cf[i];
				cnt++;
			}else{
				break;
			}
		}
		ans=max(cnt,ans);			
	}
	cout << ans;
	return 0;
}
