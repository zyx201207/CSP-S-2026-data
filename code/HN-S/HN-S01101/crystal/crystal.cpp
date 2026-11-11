#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long M=1e12+5;
int n;
long long m; 
long long a[N];
int ans=0;
int get(long long tar){
	long long sum=0;
	int cnt=0;
	int idx=upper_bound(a+1,a+n+1,tar)-a-1;
//	cout<<"id:"<<idx<<" ";
	for(int i=idx;i>=1;i--){
		if(sum+tar-a[i]>m){
			ans=max(ans,cnt);
//			cout<<"cnt:"<<cnt<<"\n";
			return cnt;
		}
		sum+=tar-a[i];
		cnt++;
	}
//	cout<<"cnt:"<<cnt<<"\n";
	ans=max(ans,cnt);
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long l=M,r=-M;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	sort(a+1,a+n+1);
	while(l<r){
		long long lmid=l+(r-l+2)/3,rmid=r-(r-l+2)/3;
//		cout<<lmid<<" "<<rmid<<"\n";
		if(get(lmid)<=get(rmid)){
			l=lmid;
		}else{
			r=rmid;
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
