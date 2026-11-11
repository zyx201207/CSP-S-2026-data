#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],now,las,head=1,sum=1;
bool cmp(int a,int b){
	return a>b;
}
int num(int x){//O(30n)
	int tmp=x,cnt=0;
	while(tmp){
		tmp/=2;
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1,cmp);
	las=num(a[1]);
	for(int i=2;i<=n;i++){
		now=num(a[i]);
		if(las==now)sum++;
		else sum=1,head=i;
		if(sum==m)break;
		las=now;
	}
	if(sum==m){
		int ans=a[head];
		for(int i=head+1;i<=head+m-1;i++)ans=ans&a[i];
		cout<<ans<<endl;
	}else{
		if(n==m){
			int ans=a[1];
			for(int i=2;i<=n;i++)ans=ans&a[i];
			cout<<ans<<endl;
		}else{
			int ans=a[1];
			for(int i=2;i<=m;i++)ans=ans&a[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
