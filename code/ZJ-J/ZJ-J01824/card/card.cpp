#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],ans[M],pre[M];
struct eti{
	int tm;
	bool v;
}cnt[N];
int f=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[a[i]]++;
		if(a[i]<a[i-1]){
			f=0;
		}
	}
	if(f==1){
		for(int i=1;i<=m;i++){
			pre[i]=pre[i-1]+pre[i];
		}
		for(int i=1;i<=m;i++){
			cout<<pre[i]<<" ";
		}
		return 0;
	}
	for(int t=1;t<=n;t++){
		for(int i=1;i<=m;i++){
			cnt[i].v=0;
			cnt[i].tm=0;
		}
		for(int i=t;i<=n;i++){
			if(cnt[a[i]].v==0){
				if(cnt[a[i]].tm==0) cnt[a[i]].tm=i;
				cnt[a[i]].v=1;
			}
			else{
				for(int k=1;k<=m;k++){
					if(cnt[k].tm>cnt[a[i]].tm){
						cnt[k].v=0;
						cnt[k].tm=0;
					}
				}
				cnt[a[i]].tm=i;
				cnt[a[i]].v=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(cnt[i].v==1){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}