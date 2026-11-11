#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[300005],last[300005]; 
bool check(){
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1])return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check()){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cnt[a[i]]=i;
			}
		}
	}
	else if(m<=2){
		if(m==1)cnt[1]=n;
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==a[n]){
					cnt[a[n]]++;
				}
				else {
					cnt[1]++;
					cnt[2]++;
				}
			}
		}
	} 
	else{
		for(int T=1;T<=n;T++){
			for(int i=1;i<=m;i++)last[i]=0;
			for(int i=T;i<=n;i++){
				if(last[a[i]]==0){
					last[a[i]]=i;
				}
				else{
					for(int j=1;j<=m;j++){
						if(last[j]>last[a[i]]){
							last[j]=0;
						}
					}
				}
			}
			for(int i=1;i<=m;i++){
				if(last[i]!=0){
					cnt[i]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
