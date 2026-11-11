#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,a[2000005];
int ti[2000005];
int ans=114514191;
int anss=0;
void dfs(int x,int sum,int vv){
	if(x>vv){
		return;
	}
	if(x==vv){
		ti[sum]++;
		ans=min(ans,sum);
		return;
	}
	int cnt=0;
	for(int i=x+1;i<=vv;i++){
		cnt+=a[i]-a[i-1];
		if(cnt<=d){
			dfs(i,sum+1,vv);
		}
		if(cnt>d){
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.in","r",stdin);
	cin>>c>>t;
	while(t--){
		anss=0;
		memset(ti,0,sizeof(ti));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i-1<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cntt=1;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[k-1]>d){
						cntt=0;
						break;
					}
				}
				if(cntt==0){
					break;
				}
				memset(ti,0,sizeof(ti));
				ans=114514191;
				dfs(i,0,j);
				if(ti[ans]==2){
//					cout<<i<<" "<<j<<endl;
					anss++;
				}
			}
		}
		cout<<anss<<endl;
	}
}