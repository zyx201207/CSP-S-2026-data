#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int cnt[N];
bool f[N];
int last[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int l=n+1;
		int r=0;
		for(int j=i;j<=n;j++){
			if(last[a[j]]){
				if(last[a[j]]<l){
					l=last[a[j]];
				}
				r=j-1;
			}
			last[a[j]]=j;
		}
		for(int j=1;j<=n;j++) last[a[j]]=0;
		if((l==n+1)&&(r==0)){
			for(int j=i;j<=n;j++){
				cnt[a[j]]++;
			}
		}
		else{
			for(int j=i;j<=n;j++){
			if((j<l)||(j>r)){
				cnt[a[j]]++;
			}
		}
		}
		
	}
	for(int i=1;i<=m;i++) cout<<cnt[m]<<' ';
	return 0;
}
