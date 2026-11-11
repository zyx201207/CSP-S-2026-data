#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans[500005],t[500005];
bool flag=true;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) flag=false;
	}
	if(flag==true){
		int num=1;
		for(int i=1;i<=n+1;i++){
			if(a[i]!=num){
				cout<<i-1<<" ";
				num=a[i];
			}
		}
		return 0;
	}
	for(int k=1;k<=n;k++){
		for(int i=0;i<=m;i++) t[i]=0;
		for(int i=k;i<=n;i++){
			if(t[a[i]]==0) t[a[i]]=i;
			else{
				for(int j=1;j<=m;j++){
					if(t[j]>t[a[i]]) t[j]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]!=0) ans[j]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<' ';
	}
	return 0;
}