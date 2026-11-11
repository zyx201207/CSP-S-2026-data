#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e5+5;
int n,m,a[N],last[M],c[M],cnt[M],t[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		last[i]=-1;
		cnt[i]=0;
		t[i]=-1;
	}
	int l=0;
	for(int i=n;i>=1;i--){
		if(last[a[i]]==-1){
			c[++l]=a[i];
			last[a[i]]=l;
			t[a[i]]=n-i+1;
		}
		else{
			for(int j=last[a[i]]+1;j<=l;j++){
				cnt[c[j]]+=(n-i+1-t[c[j]]);
				last[c[j]]=-1;
				t[c[j]]=-1;
			}
			l=last[a[i]];
		}
	}
	for(int j=1;j<=l;j++){
		cnt[c[j]]+=(n-t[c[j]]+1);
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
