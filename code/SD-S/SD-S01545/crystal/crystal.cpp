#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int a[N],n,m,maxa,ans,ans_final,jl[N],cha[N],chaa,cnt,sum;
bool flag;
void dfs(int cnt){
	if(cnt==m){
		memset(jl,0,sizeof(jl));
		for(int i=1;i<=n;i++){
			jl[a[i]]++;
		}
		for(int i=1;i<=maxa-2;i++){
			ans=max(ans,jl[i]);
		}
		ans_final=max(ans_final,ans);
		return;
	}
	for(int i=1;i<n;i++){
		a[i]++;
		dfs(cnt+1);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		if(i>=2){
			cha[i-1]=a[i]-a[i-1];
		}
		if(i>=3&&flag==1){
			if(cha[i-2]!=cha[i-1]){
				flag=0;
			}
		}
	} 
	if(flag==1){
		chaa=cha[2];
		cnt=1;
		sum=0;
		while(sum<=m){
			sum=sum+cnt*chaa;
			cnt++;
		}
		cout<<cnt-1<<endl;
		return 0;
	}
	else{
		dfs(0);
		cout<<ans_final<<endl;
	}
	return 0;
} 
