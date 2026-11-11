#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct node{
	long long x,num;
}a[200005];
bool cmp(node a,node b){
	if(a.num==b.num){
		return a.x>b.x;
	}
	return a.num>b.num;
}
bool cmpa(node a,node b){
	return a.x>b.x;
}
long long maxa,num=(long long)pow(2,31)-1;
bool vis[200005];
void dfs(long long x,long long sum){
	if(x>n||sum>=m){
		if(sum==m){
			maxa=max(maxa,num);
		}
		return;
	}
	for(int i=x;i<=n;i++){
		vis[i]=1;
		long long j=num;
		num&=a[i].x;
		dfs(i+1,sum+1);
		num=j;
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("and4.in","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		long long t=a[i].x;
		while(t>0){
			if(t^2==1){
				a[i].num++;
			}
			t>>=1;
//			cout<<t<<"\n";
		}
//		cout<<a[i].num<<"\n";
	}
	if(n<=2000){
		dfs(1,0);
		cout<<maxa;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].x;
	sort(a+1,a+n+1,cmpa);
	if(n==1){
		cout<<a[1].x;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i].x==ans){
			if(n-i+1>=m){
				for(int j=1;j<=m;j++){
					ans&=a[j+i-1].x;
				}
				cout<<ans;
				return 0;
			}
			else{
				for(int j=i;j<=n;j++){
					ans&=a[j].x;
				}
				for(int j=1;j<=m-(n-i+1);j++){
					ans&=a[j].x;
				}
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}
