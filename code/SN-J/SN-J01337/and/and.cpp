#include<bits/stdc++.h>
using namespace std;
long long ans[200010];
bool cmp(long long a,long long b){
	return a>=b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>ans[i];
	}
	sort(ans,ans+n,cmp);
	long long tot=ans[0];
	if(m==2){
		tot=tot&ans[1];
	}
	for(long long i=1;i<m-1;i++){
		tot=tot&ans[i+1];
	}
	cout<<tot;
	return 0;
}
