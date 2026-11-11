#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[2000005],d,cnt,ans,anss,f[2000005];
void dfs(int num,int end,long long sum){
    if(num==end){
        if(sum<ans){
        	ans=sum;
        	cnt=1;

		}
		else if(sum==ans){
			cnt++;
		}
		return;
	}
	for(int i=num+1;i<=end;i++){
		if(x[i]-x[num]>d) break;
		dfs(i,end,sum+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n;
        cin>>d;
        ans=1e18;
        anss=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
        	memset(f,0,sizeof f);
        	for(int j=i+1;j<=n;j++){
                f[j]=1e18;
			}
        	for(int j=i+1;j<=n;j++){
        		ans=1e18;
        		cnt=1;
                dfs(i,j,0);
                if(cnt==2) anss++;
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}