#include<bits/stdc++.h>
using namespace std;
int n;
int x[2000005];
int ans[200005],num=999999999;
int c,t;
int d;
int r=0;

void dfs(int start,int end,int l){
	if(start==end){
		ans[l]++;
		num=min(num,l);
		return;
	}
	for(int i=start+1;i<=end;i++){
		if(x[i]-x[start]<=d){
			dfs(i,end,l+1);
		}
		else	return;
	}
	return;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		r=0;
		bool A=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=3){
				if(x[i]-x[i-1]!=x[i-1]-x[i-2])	A=0;
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				fill(ans,ans+200000,0);
				num=999999999;
				int f=1;
				for(int k=i;k<j;k++){
					if(x[k+1]-x[k]>d){
						f=0;
						break;
					}	
				}
				if(f){
					dfs(i,j,0);
					if(ans[num]==2)	r++;
				}
			}
		}
		cout<<r<<"\n";
	}
	return 0;
}