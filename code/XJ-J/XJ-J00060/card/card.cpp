#include<bits/stdc++.h>
using namespace std;
int n,m,s,t[300001],a[500001];
vector<int>x[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int t1[m+1];
		for(int j=1;j<=m;j++)t1[j]=0;
		for(int j=i;j<=n;j++){
			if(t1[a[j]]!=0)for(int k=t1[a[j]];k<=j;k++)t1[a[k]]=0;
			t1[a[j]]=j;
		}
		for(int i=1;i<=m;i++)if(t1[i]!=0)t[i]++;
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
	return 0;
}
