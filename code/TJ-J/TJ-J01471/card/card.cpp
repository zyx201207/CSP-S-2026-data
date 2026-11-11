#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int b[N];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int bj=0;
	for(int i=1; i<=n; i++){
		if(a[i]!=b[i]){
			bj=1;
		}
	}
	if(!bj){
		for(int i=1; i<=m; i++){
			cout<<0<<" ";
		}
		return 0;
	}
	for(int i=1; i<=n; i++){
		int t[205]={},fpos[205]={};
		for(int j=i; j<=n; j++){
			t[a[j]]++;
			int lsid=-1;
			for(int k=i; k<j; k++){
				if(a[j]==a[k]){
					lsid=k;
					break;
				}
			}
			if(lsid!=-1){
				for(int k=lsid; k<j; k++){
					t[a[k]]--;
				}
			}
		
		}
		for(int j=1; j<=m; j++){
			if(t[j]>=1){
				ans[j]++;
			}
		}
	}
	for(int i=1; i<=m; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
