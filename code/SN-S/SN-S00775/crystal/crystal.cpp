#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+6;

int n;
ll m,a[maxn];
bool cmp(int x,int y){
	return x>=y;
}
int ans=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		int p=m;
		for(int j=i+1;j<=n;j++){
			if(p>0){
				if(a[i]-a[j]>=p){
					p-=abs(a[i]-a[j]);
					ans=max(ans,abs(j-i+1));
					
				}
			}
			
		}
	}
	cout << ans;
	return 0;
}

