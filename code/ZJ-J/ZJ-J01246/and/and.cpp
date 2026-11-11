#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],ans=0,mx=0,qwq=2147483647;
map<int,int> t;
void dfs(int num,int sum,int q){
	if(num==n+1){
		if(q<m)return ;
		ans=max(ans,sum);
		return ;
	}
	dfs(num+1,sum,q);
	sum&=a[num];
	dfs(num+1,sum,q+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]),qwq&=a[i],t[a[i]]+=1;
	if(n<=20){//1~5
		dfs(1,2147483647,0);
		cout<<ans;
		return 0;
	}
	else if(m==1){//6
		cout<<mx<<"\n";
	}
	else if(m==n){//7
		cout<<qwq<<"\n";
	}
	else if(n<=3000 and m==2){//8~10;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				int ovo=a[i]&a[j];
				ans=max(ans,ovo);
			}
		}
		cout<<ans;
	}
	else{//13
		int summ=0;
		for(int i=1;i<=2147483647;i=i*2+1){
			summ+=t[i];
		}
		if(summ==n){
			sort(a+1,a+n+1);
			cout<<a[n-m+1];
			return 0;
		}
	}
	return 0;
}

