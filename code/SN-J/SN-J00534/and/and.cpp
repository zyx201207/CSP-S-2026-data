#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define int long long
int n,m,a[200050],ans1=-1,ans2=0,ans=1,mx=-1;
int plan[200050],used[200050];
void dfs(int step){
	if(step>m){
		for(int i=1;i<=n;i++) if(plan[i]){
			ans=a[i];
			break;
		} 
		for(int i=1;i<=n;i++) if(plan[i]) ans&=a[i];
		mx=max(mx,ans);
	}
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		plan[i]=1;
		used[i]=1;
		dfs(step+1);
		used[i]=0;
		plan[i]=0;
	}
}
#define int int
int main(int argc, char** argv) {
	#define int long long
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans2=a[1];
	for(int i=1;i<=n;i++){
		ans1=max(ans1,a[i]);
		ans2&=a[i];
	} 
	if(m==1) cout<<ans1;
	else if(m==n) cout<<ans2;
	else if(m==2){
		int ans3=-1;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans3=max(ans3,a[i]&a[j]);
		cout<<ans3;
	}else{
		dfs(1);
		cout<<mx;
	}
 	return 0;
}
