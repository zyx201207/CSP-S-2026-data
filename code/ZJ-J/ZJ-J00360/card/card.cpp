#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000010],used[1000010],cha[1000010],s[1000010],sum[1000010];
bool check(){
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1])return 0;
	}
	return 1;
}
void slove(){
	//cout<<11111;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			used[a[i]]=i;
		}
		cha[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		sum[i]+=used[i];
		printf("%lld ",sum[i]);
	}
	
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(check()){
		slove();
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			used[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(used[a[j]]==0){
				used[a[j]]=j;
			}
			else{
				for(int k=used[a[j]];k<j;k++){
					used[a[k]]=0;
				}
				used[a[j]]=j;
			}
			
		}
		for(int j=1;j<=m;j++){
			if(used[j]){
				sum[j]++;
			}
		}
	} 
	for(int i=1;i<=m;i++){
		printf("%lld ",sum[i]);
	}
	//I love CCF very much
	return 0;
}

