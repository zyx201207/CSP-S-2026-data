#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL maxV=-1e9,n,m,a[200005],ans=-1e9,p,q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) p=a[i],q=a[i];
		else p=a[i]&p;
		q=max(q,q&a[i]);
		ans=max(ans,a[i]);
	}
	if(m==n){
		LL s=a[1];
		for(LL i=2;i<=n;i++){
			s=s&a[i];
		}
		cout<<a;
		return 0;
	}
	else if(m==n-1){
		LL op=-1e9;
		for(LL i=1;i<=n;i++){
			op=max(op,p^a[i]);
		}
		cout<<op;
		return 0;
	}
	else if(m==1){
		cout<<ans;
		return 0;
	}
	else if(m==2){
		LL op=-1e9;
		for(LL i=1;i<=n;i++){
			for(LL j=i+1;j<=n;j++){
				op=max(op,a[i]&a[j]);
			}
		}
		cout<<op;
		return 0;
	}
	else{
		cout<<q;
	}
	return 0;
} 
