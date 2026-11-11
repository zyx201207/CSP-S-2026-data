#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<long long>a,b;
map<long long,long long>mp;
int Find(long long shu,long long top){
	for(long long i=1;i<=top;i++){
		if(b[i]==shu){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	a.resize(n+1);
	b.resize(2*n+1);
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int top=1;
	for(long long i=1;i<=n;i++){
		long long S=Find(a[i],top);
		if(S==0){
			top++;
			b[top]=a[i];
		}else{
			for(long long j=S;j<=top;j++){
			b[j]=0;	
			}
			top++;
			b[top]=a[i];
				
		}
		for(long long j=1;j<=top;j++){
			if(b[j]){
				mp[b[j]]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<mp[i]<<' ';
	}
	return 0;
}
