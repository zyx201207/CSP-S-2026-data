#include<bits/stdc++.h>
using namespace std;
const int maxn=2000010;
int c,t;
int isl[maxn];
int dfs(int start,int end,int step,int abl){
	if((isl[end]-isl[start])<=abl){
		return step;
	}
	for(int i=start+1;i<end;i++){
		if(isl[i]-isl[start]<=abl){
			return dfs(i,end,step+1,abl);
		}
		return 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,ans=0;
		for(int i=1;i<=n;i++){
			cin>>isl[i];
		}
		int l=1,r=3;
		while(l<=n && r<=n){
			int flag=0,cnt=0,mnstep=INT_MAX;
			int curs=dfs(l,r,0,d);
			if(curs<mnstep){
				cnt=0;
				mnstep=curs;
			}else if(curs==mnstep){
				cnt++;
				if(cnt==2){
					flag=1;
				}else{
					flag=0;
				}
			}
			if(flag){
				ans++;
				r++;
			}else{
				l++;
				r++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
