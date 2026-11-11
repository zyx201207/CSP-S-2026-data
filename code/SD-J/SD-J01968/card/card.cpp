#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int ans[300005],a[500005],t[500005],q[500005];
bool ans2[300005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int tt=0;
		memset(t,0,sizeof(t));
		memset(q,0,sizeof(q));
		memset(ans2,0,sizeof(ans2));
		for(int j=i;j<=n;j++){
			if(t[a[j]]!=0&&tt>=t[a[j]])
				tt=t[a[j]]-1;
			q[++tt]=a[j];
			t[a[j]]=tt;
		}
		for(int j=1;j<=tt;j++){
			if(ans2[q[j]]==0)
				ans[q[j]]++;
			ans2[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
