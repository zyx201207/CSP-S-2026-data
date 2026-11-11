#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
void fast_read(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
}
int n,m,a[N],pos[N],cnt[N];
int game[N],top,last[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	fast_read();
	cin>>n>>m;
	bool xingzhiA=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)
		if(a[i]>a[i+1])xingzhiA=0;
	if(xingzhiA){
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		for(int i=1;i<=m;i++)cnt[i]+=cnt[i-1];
		for(int i=1;i<=m;i++)
			cout<<cnt[i]<<' ';
	}
	else{
		for(int i=n;i>0;i--)
			if(!last[a[i]])last[a[i]]=i;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;){
				if(last[a[j]]>j)j=last[a[j]];
				else{
					cnt[a[j]]++;
					j++;
				}
			}
		}
		for(int i=1;i<=m;i++)
			cout<<cnt[i]<<' ';
	}
	return 0;
}
