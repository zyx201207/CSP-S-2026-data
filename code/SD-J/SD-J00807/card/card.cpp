#include<bits/stdc++.h>
using namespace std;
int a[500005];
int fl[500005];
int lst[500005];
int s[500005];
bool flg[300005];
int ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000&&m<=3000){
		for(int i=n;i>=1;i--){
			fl[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				flg[j]=0;
			}
			for(int j=i;j<=n;j++){
				flg[a[j]]|=1;
				if(fl[j]!=0){
					j=fl[j]-1;
				}
			}
			for(int j=1;j<=m;j++){
				ans[j]+=(int)(flg[j]);
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n]){
				ans[a[i]]++;
			}
			else{
				ans[1]++;
				ans[2]++;
			}
		}
		cout<<ans[1]<<" "<<ans[2];
	}
	else{
		for(int i=1;i<n;i++){
			if(a[i]!=a[i+1]){
				ans[a[i]]=i;
			}
		}
		ans[n]=m;
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
