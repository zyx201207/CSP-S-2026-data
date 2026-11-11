#include<bits/stdc++.h>
using namespace std;
int check(int table[],int k,int n){
	for(int i=0;i<n+5;i++){
		if(table[i]==k)return i;
		if(table[i]==-1)return -1;
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m,n;
	cin>>n>>m;
	int a[n+5],ans[m+5];
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int table[n+5],hand[n+5],zz=0,xzdzz=0;
		for(int t=i;t<=n;t++)hand[zz++]=a[i];
		for(int iii=0;iii<n+5;iii++)table[iii]=-1;
		for(int ll=0;ll<zz;ll++){
			int tz=check(table,hand[ll],n);
			for(int p=0;p<n+5;p++)cout<<table[p]<<" ";
			cout<<endl;
			if(tz=!-1){
				for(int p=tz;p<n+5;p++)table[p]=-1;
				table[tz-1]=hand[ll];
				xzdzz=tz-1;
			}else{
				table[xzdzz++]=hand[ll];
			}
		}
		for(int gunmu=0;gunmu<n+5;gunmu++)if(table[gunmu]>0&&table[gunmu]<=m)ans[table[gunmu]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
