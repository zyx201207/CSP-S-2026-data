#include<bits/stdc++.h>
using namespace std;
long long int n,m,num[200005],maxn=0;
void dfs(int now,int cnt,int an){
	if(cnt>m){
		if(now<=n){
			maxn=max(maxn,an&=num[cnt]);
		}
		return;
	}
	dfs(now+1,cnt+1,num[now+1]);
	dfs(now+1,cnt,num[now+1]);
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	int b=num[1];
	dfs(1,0,num[1]);
	cout<<maxn;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,num[i]&num[j]);
			}
		}
		cout<<maxn;
	}else{
		sort(num,num+1+n);
		if(m==1){
			cout<<num[1];
		}
	}
	return 0;
}
