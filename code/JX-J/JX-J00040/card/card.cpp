#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int b[M];
int cnt[M];
int sum[M];
int st[N];
void erased(int l,int r){
	for(int i=l;i<=r;i++){
		if(!st[i]){
			b[a[i]]=0;
		    sum[a[i]]--;
		}
		st[i]=1;
		
	}
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		memset(sum,0,sizeof sum);
		memset(st,0,sizeof st);
		for(int j=i;j<=n;j++){
			sum[a[j]]++;
			if(b[a[j]]!=0){
				erased(b[a[j]],j-1);
				b[a[j]]=j;
			}
			else b[a[j]]=j;
		}
		for(int k=1;k<=m;k++)if(sum[k]>0)cnt[k]++;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';		
    return 0;
}
