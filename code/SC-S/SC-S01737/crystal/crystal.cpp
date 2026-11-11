#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,line[N],ans=0;
bool cmp(long long x,long long y){
	return x<y;
}
void init(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>line[i];
	}
}

void solve(){
	sort(line+1,line+1+n,cmp);
	long long l=1,r=1,cur=line[1];
	while(r<n){
		r++;
		cur+=line[r];
		while((r-l+1)*line[r]-cur>m){
			cur-=line[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	init();
	solve();
	
	return 0;
}
/*
5 5
1 2 4 8 9

5 8 
-3 -1 2 2 7

*/