#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int s[500010];
int instack[500010];
int cnt[500010];
int n,m;
int endq;
void FA(){
	for(int t=n-1;t>=0;t--){
		if(a[t+1]!=a[t]){
			cnt[a[t]]++;
		}
	}
	int base=1;
	for(int i=1;i<=n;i++,base++){
		cnt[a[i]]*=base;
	}
	for(int i=1;i<=m;i++){
		cout<<fixed<<setprecision(0)<<cnt[i]<<" ";
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	bool A=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>0 && a[i-1]>a[i])A=0;
	}
	// if(A){
	// 	FA();
	// 	return 0;
	// }
	for(int T=0;T<n;T++){
		endq=0;
		for(int i=0;i<=m;i++){
			instack[i]=0;
		}
		for(int i=T;i<n;i++){
			//cout<<instack[a[i]]<<"->";
			if(instack[a[i]]){
				while(endq>0 && a[s[endq-1]]!=a[i]){
					instack[a[s[endq-1]]]--;
					endq--;
				}
				s[endq-1]=i;
			}
			else{
				instack[a[i]]++;
				s[endq++]=i;
			}
		}
		for(int i=1;i<=m;i++){
			if(instack[i])cnt[i]++;
		}
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}