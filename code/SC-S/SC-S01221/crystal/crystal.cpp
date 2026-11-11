#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=5e5+5;
int n;
ll m;	
ll a[maxn];
int main(){
	freopen("crystal.in","r",stdin);	
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mx=0;
	for(int i=n;i>=1;i--){
		int cnt=1;
		ll x=m;
		int j=i-1;
		while(x>0 && j > 0){
			
			if(a[i]-a[j] <= x){
				
				x-=a[i]-a[j];
				j--;
				++cnt;
				
				
			}else{
				x-=a[i]-a[j];
			}
			
			
		}
		
		mx=max(mx,cnt);
	}
	cout<<mx<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}