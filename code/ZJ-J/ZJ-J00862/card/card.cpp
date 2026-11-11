#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int cnt[N];
int last[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=10000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]){
					last[i]=j;
				}
			}
		}
//		for(int i=1;i<=n;i++) cout<<last[i]<<" ";
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;){
//				cout<<j<<" ";
				if(last[j]){
					cnt[a[j]]++;
					j=last[j]+1;	
				}else cnt[a[j]]++,j++;		
			}
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		return 0;
	}else{
		for(int i=1;i<=m;i++) cout<<i<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
