#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,maxn;
ll m,a[500010],add,now;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ax=abs(a[1]); 
	for(int i=1;i<=n;i++){
		a[i]+=ax;
	}
	for(int l=1,r=1;l<=r&&r<=n;r++){
		add+=a[r]-a[r-1];
		now+=(a[r]-a[r-1])*(r-l);
		while(now>m&&l<=r){
			l++;
			now-=add;
			add-=a[l+1]-a[l]; 
		}
		if(now>m) break;
		if(l>r) break;
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
