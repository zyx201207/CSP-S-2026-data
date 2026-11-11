#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	long long s;
};
node a[500005];
long long q[500005];
int cmp(node x,node y){
	return x.s<y.s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i].x=i;
		cin>>a[i].s;
	}
	sort(a+1,a+n+1,cmp);
	int ans=1;
	for(int i=1;i<=n;i++){
		if(m>=i*(a[i+1].s-a[i].s)){
			m-=i*(a[i+1].s-a[i].s);
			ans++;
		}else{
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
