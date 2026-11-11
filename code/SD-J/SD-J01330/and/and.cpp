#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200050],maxx=-99999,cnt=1,ans;
void b(){
	if(cnt>m){
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(cnt==1){
			ans=a[i];
		}
		long long t1=ans,t2=a[i];
		ans&=a[i];
		a[i]=0;
		cnt++;
		b();
		a[i]=t2;
		cnt--;
		ans=t1;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b();
	cout<<maxx;
	return 0;
}
