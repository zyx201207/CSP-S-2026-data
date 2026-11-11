#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e5+5;
int n,m,a[N];
string tobin(int x){
    string ans="";
    while(x>0){
        char c=x%2+'0';
        ans+=c;
        x>>=1;
    }
    while(ans.size()<31) ans+='0';
    reverse(ans.begin(),ans.end());
    return ans;
}
int dfs(int p,int cur,int dep){
    if(dep>m){
        return cur;
    }
    int ans=-1;
    for(int i=p+1;i<=n;i++){
        ans=max(dfs(i,cur,dep),dfs(i,cur&a[i],dep+1));
    }
    return ans;
}

main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
        int sum=-1;
        for(int i=1;i<=n;i++) sum=max(sum,a[i]);
        cout<<sum<<endl;
        return 0;
	}
	if(m==2){
        int sum=-1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                sum=max(sum,a[i]&a[j]);
            }
        }
        cout<<sum<<endl;
        return 0;
	}
	if(n==m){
        int sum=INT_MAX;
        for(int i=1;i<=n;i++) sum&=a[i];
        cout<<sum<<endl;
        return 0;
	}
	cout<<dfs(1,INT_MAX,0)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
