#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,j,k,x,cnt,res;
int a[510000],b[510000],fl[310000],ans[310000],mp[310000];
bool check(){
	int i;
	for(i=1;i<=n-1;i++){
		if(a[i]>a[i+1]) return 0;
	}
	return 1;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    if(n<=500){
    	for(i=1;i<=n;i++){
    		cnt=0;
    		res=0;
    		for(j=i;j<=n;j++){
    			if(mp[a[j]]){
    				x=cnt;
    				for(k=mp[a[j]];k<=x;k++){
    					cnt--;
    					mp[b[k]]=0;
					}
				}
				cnt++;
				mp[a[j]]=cnt;
				b[cnt]=a[j];
			}
			for(j=1;j<=cnt;j++) fl[b[j]]=1;
			for(j=1;j<=m;j++){
				ans[j]+=fl[j];
				fl[j]=0;
				mp[j]=0;
			}
		}
		for(i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else if(check()){
		for(i=1;i<=n;i++) fl[a[i]]=i;
		for(i=1;i<=m;i++) cout<<fl[i]<<" ";
	}
	else if(m<=2){
		for(i=1;i<=n;i++){
			if(a[i]==a[n]) fl[a[n]]++;
			else{
				fl[1]++;
				fl[2]++;
			}
		}
		for(i=1;i<=m;i++) cout<<fl[i]<<" ";
	}
	else if(n<=5000){
		for(i=1;i<=n;i++) mp[a[i]]=i;
		for(i=1;i<=n;i++){
			cnt=0;
			for(j=i;j<=n;j++){
				b[++cnt]=a[j];
				j=mp[a[j]];
			}
			for(j=1;j<=cnt;j++) fl[b[j]]=1;
			for(j=1;j<=m;j++){
				ans[j]+=fl[j];
				fl[j]=0;
			}
		}
		for(i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else{
		for(i=1;i<=m;i++) cout<<i<<" ";
	}
}