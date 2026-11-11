#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],cnt[35],ans,cnt1[35];
bool cmp(long long a,long long b){
	return a>b;
}
vector<long long> ls,ls1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ls.push_back(a[i]);
		for(int k=30;k>=0;k--) if(a[i]&(1<<k)) cnt[k]++;
	}
	sort(ls.begin(),ls.end(),cmp);
	for(int i=30;i>=0;i--){
		if(cnt[i]<m) continue;
		int len=ls.size();
		for(int k=0;k<len;k++){
			if(ls[k]&(1<<i)) ls1.push_back(ls[k]);
		}
		ls=ls1;
		memset(cnt1,0,sizeof(cnt1));
		len=ls.size();
		for(int k=0;k<len;k++){
			for(int st=30;st>=0;st--) if(ls[k]&(1<<st)) cnt1[st]++;
		}
		for(int i=30;i>=0;i--) cnt[i]=cnt1[i];
		ls1.clear();
		ans+=(1<<i);
	}
	cout<<ans;
	return 0;
}
