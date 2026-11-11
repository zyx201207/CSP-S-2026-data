#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL t[300005],a[500005];
struct node{
	LL cnt,x;
};
node v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	for(LL i=1;i<=n;i++){
		for(LL i=1;i<=m;i++){
			v[i].cnt=(LL)0;
			v[i].x=(LL)-1;
		}
		for(LL j=i;j<=n;j++){
			if(v[a[j]].cnt>0){
				LL p=v[a[j]].x;
				for(LL k=p;k<=j-1;k++){
					v[a[k]].cnt--;
					if(v[a[k]].cnt==0) v[a[k]].x=-1;
				}
			}
			v[a[j]].cnt++;
			if(v[a[j]].cnt==1){
				v[a[j]].x=j;
			}
		}
		for(LL j=1;j<=m;j++){
			if(v[j].cnt>0) t[j]++;
		}
	}
	for(LL i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 