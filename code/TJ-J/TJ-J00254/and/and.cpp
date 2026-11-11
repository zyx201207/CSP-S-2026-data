#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200010],cnt;
int b[200010];
map<int,int>box;
int ans;
bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(!box[b[i]]) a[++cnt]=b[i];
		box[b[i]]++;
	}
	sort(a+1,a+cnt+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(box[a[i]]>=m){
			ans=max(ans,a[i]);
		}
	}
	int z=a[1];
	for(int i=1;i<=m;i++){
		z&=a[i];
	}
	int z1=b[1];
	for(int i=1;i<=m;i++){
		z1&=b[i];
	}
	int z2=0;
	if(m==2&&n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int z3=b[i]&b[j];
				z2=max(z2,z3);
			}
		}
	}
	cout<<max(max(max(ans,z),z1),z2);
	return 0;
}
