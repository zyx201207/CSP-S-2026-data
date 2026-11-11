#include<bits/stdc++.h> 

using namespace std;

const int N=5e5+5;
int a[N],fl[N],ans[N];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	if(n<=500) {
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				if(fl[a[j]]) 
					for(int k=fl[a[j]];k<=j;k++) fl[a[k]]=0;
				fl[a[j]]=j;
			}
			for(int j=1;j<=m;j++) if(fl[j]) ans[j]++;
			memset(fl,0,sizeof fl);
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else {
		for(int i=1;i<=n;i++) fl[a[i]]++;
		int sum=0;
		for(int i=1;i<=m;i++) cout<<sum+fl[i]<<" ",sum+=fl[i];
	}
	return 0;
}
