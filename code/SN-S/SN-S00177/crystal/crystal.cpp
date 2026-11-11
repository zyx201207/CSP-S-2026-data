#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PID "crystal"
#define FIN freopen(PID".in","r",stdin)
#define FOU freopen(PID".out","w",stdout)
const int N=5e5+5;
int n,m,a[N],pre[N],ANS;

bool check(int st,int i){
	if(i==st) return 1;
	int sum=pre[i-1]-pre[st-1];
	if((sum+m)/(i-st)>=a[i]) return true;
	return false;
}

signed main(){
	FIN;
	FOU;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n,ans=1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(i,mid)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		ANS=max(ANS,ans-i+1);
	}
	cout<<ANS;
	return 0;
}
