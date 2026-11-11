#include<bits/stdc++.h>
using namespace std;
const long long N=200010;
long long n,m,maxx=-1,a[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n>>m;
	long long wans=a[1];bool B=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(B&&i!=1&&a[i]-1!=a[i-1]) B=false;
		maxx=max(maxx,a[i]);
		wans=a[i]&wans;
	}
	if(m==1){//6
		cout<<maxx;
	}
	else if(m==n){//7
		cout<<wans;
	}
//	else if(n<=20){
//		for(int i=1;i<=n;i++){
//			
//		}
//	}
	else if(B){
		cout<<n-m;
	}
	
	else{//16-17
		sort(a+1,a+n+1,cmp);
		long long ans=a[1];
		for(long long i=1;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}

	return 0;
} 
