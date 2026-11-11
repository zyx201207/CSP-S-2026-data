#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5+6;

int n,m;
int a[maxn],tong[maxn];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		tong[a[i]]++;
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout << a[1];
		return 0;
	}
	if(m==2){
		int ans;
		if(a[2]==a[3])cout << a[2]; 
		if(a[1]-a[2]==1&&(a[1]&a[2])==0){
			ans = a[2]&a[3];
			cout << ans;
		}
		return 0;
	}
	if(tong[1]+tong[2]+tong[3]==n){
		if(tong[1]+tong[3]>=m) cout << 1;
		else cout << 0;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout << ans;
		return 0;
	}
	cout << a[m];
	return 0;
}

