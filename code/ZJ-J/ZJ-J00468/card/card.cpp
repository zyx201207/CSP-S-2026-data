#include<bits/stdc++.h>
using namespace std;
int n,m;
int ar[500005],cnt[300005],ans[300005],s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		if(i>1&&ar[i]<ar[i-1]) f=0;
		cnt[ar[i]]++;
	}
	for(int i=1;i<=m;i++){
		s[i]=s[i-1]+cnt[i];
	}
	if(f==1){
		for(int i=1;i<=m;i++){
			cout<<s[i]<<' ';
		}
		return 0;
	}
	for(int t=1;t<=n;t++){
		int l=t;
		if(t>1) cnt[ar[t-1]]--;
		int a=ar[l];
		if(cnt[a]>1){
			l++;
			while(ar[l]!=a){
				l++;
			}
		}
		for(int j=l;j<=n;j++){
			ans[ar[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}