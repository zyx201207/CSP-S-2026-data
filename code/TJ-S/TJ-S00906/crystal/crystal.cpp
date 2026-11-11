#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
void solve1(){
	long long ans=0,maxx=-1,bz,s=1;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		ans=0;
		s=1;
		for(int j=i;j>=2;j--){
			bz=a[j];
			if(ans-a[j-1]+bz>m){
				break;
			}
			ans+=bz-a[j-1];
			s++;
		}
		maxx=max(maxx,s);
	}
	cout<<maxx;
	return;
}
void solve2(){
	long long cnt=0;
	for(int i=1;i<n;i++){
		if(cnt+i>m){
			cout<<i;
			return;
		}
		cnt+=i;
	}
	cout<<cnt;
	return;
}
void solve3(){
	long long cnnt=0;
	long long gc=a[2]-a[1];
	if(gc==0){
		cout<<n;
		return;
	}
	for(int i=gc;i<gc*n;i+=gc){
		if(cnnt+i>m){
			cout<<i/gc;
			return;
		}
		cnnt+=i;
	}
	cout<<cnnt;
	return;
} 
int main(){
	 freopen("crystal.in","r",stdin);
	 freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool f=0,ff=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=i) f=1;
    	if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) ff=1;
	}
	if(!f){
		solve2();
		return 0;
	}
	if(!ff){
		solve3();
		return 0;
	}
	if(n<=5000){
		solve1();
		return 0;
	}
    return 0;
}
