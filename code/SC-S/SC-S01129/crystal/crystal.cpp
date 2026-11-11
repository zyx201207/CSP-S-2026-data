#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long m,nsum=0;
__inline int w(long long t){
	int cnt=0;
	int b=1;
	if(t<0) b=-1;
	while(t){
		cnt++;
		t/=10;
	}
	return cnt*b;
}
bool check(long long ai,int qsz,long long m,long long nsum){
	if(w(ai)+w(qsz)-1>w(m+nsum)) return 1;
	else if(ai*qsz>m+nsum) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	queue<int> q;
	int ans=0;
	for(int i=1;i<=n;i++){
		q.push(a[i]);
		nsum+=a[i];
		while(check(a[i],q.size(),m,nsum)){
			nsum-=q.front();
			q.pop();
		}
		ans=max(ans,(int)q.size());
	}
	cout<<ans;
	return 0;
} 