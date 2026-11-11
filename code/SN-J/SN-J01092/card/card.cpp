#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int last[N],L[N],t[N],flag[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int len=n-i+1;
		for(int j=1;j<=n;j++){
			flag[j]=1;
		}
		for(int j=1;j<=len;j++){
			for(int k=1;k<=m;k++){
				last[k]=L[k]=0;
			}
			for(int k=1;k<=len;k++){
				if(!flag[k]) continue;
				if(!last[a[k]]){
					L[k]=n+1;
					last[a[k]]=k;
				}else{
					L[k]=last[a[k]];
				}	
			}
			for(int k=L[j];k<j;k++){
				flag[k]=0;
			}
		}
		for(int j=1;j<=len;j++){
			if(flag[j]){
				t[a[j]]++;
			}
		}
		for(int j=1;j<=n;j++){
			a[j]=a[j+1];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
