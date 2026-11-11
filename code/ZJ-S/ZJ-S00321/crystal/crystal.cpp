#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 5e5+5;
long long a[N];
long long Ans=0;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal4.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	long long l=1,r=1,val=0;
	while(l<=r){
		if(val<=m){
			r++;
			val=val+(r-l)*(a[r]-a[r-1]);
			if(r>n){
				break;
			}
		}else{
			l++;
			val=val-(a[r]-a[l-1]);
		}
//		cout<<l<<" "<<r<<" "<<val<<"\n";
		if(val<=m){
			Ans=max(Ans,r-l+1);
		}
	}
	
	cout<<Ans;
	
	return 0;
}
