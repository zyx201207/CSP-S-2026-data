#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000005],t[300005],cnt,ans[400005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[++cnt];
		if(!t[a[cnt]])
			t[a[cnt]]++;
		else{
			for(int j=1;j<=cnt;j++){
				if(t[a[j]]){
					for(int k=j+1;k<=cnt;k++){
						a[k]=0;
						t[a[k]]=0;
					}
					cnt=j+1;
				}
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}