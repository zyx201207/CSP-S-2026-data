#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],cf[500005],t[500005],tt[500005],pre;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	cf[0]=n+1;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cf[i]=-1;
		a[n-i+1]=b[i];
	}
	for(int i=1;i<=n;i++){
		if(!t[a[i]]){
			t[a[i]]=i;
		}
		for(int j=i;j>=1;j--){
			if(t[a[j]]){
//				cout<<i<<" "<<j<<" "<<t[a[j]]<<"\n";
				cf[t[a[j]]]--;
				cf[j]++;
				j=t[a[j]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		cf[i]+=cf[i-1];
	}
	for(int i=1;i<=n;i++){
		tt[a[i]]+=cf[i];
//		cout<<a[i]<<" "<<cf[i]<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<tt[i]<<" ";
	}
	return 0;
}
//luogu_liuyuxiaozaizai
// 1 2 1 3 2 3 1 2 1 3
