#include<bits/stdc++.h>
using namespace std;
const long long N=900010;
long long n,m,cry[N];

bool cmp(int x,int y){
	return x>y;
}
long long r[N],rr[N];
long long pd(long long l[N]){
	for(int i=1;i<=n;i++){
		if(l[i]>=0) r[l[i]]++;
		else if(l[i]<0) rr[-l[i]]++;
	}
	long long maxx= -1e9;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,r[i]);
	}
	long long maxy= -1e9;
	for(int i=1;i<=n;i++){
		maxy=max(maxy,rr[i]);
	}
	return max(maxx,maxy);
}

struct tt{
	long long num;
	long long num1;
}ttt[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cry[i];
	}
	if(m==0){
		cout<<pd(cry);
		return 0;
	}
	sort(cry+1,cry+n+1,cmp);
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			ttt[i].num+=cry[i]-cry[j];
		}
		ttt[i].num1=n-i;
	}
	
	for(int i=1;i<=n-1;i++){
		if(ttt[i].num<=m){
			cout<<ttt[i].num1+1;
			return 0;
		}
	}
	cout<<1;
	return 0;
}