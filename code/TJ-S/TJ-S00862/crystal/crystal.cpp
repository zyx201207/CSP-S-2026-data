#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],cha=0;
long long n,m,maxx=1;
bool f=1,g=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cha=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(i!=1){
			if(a[i]-a[i-1]!=cha) g=0;
		}
		if(i!=a[i]) f=0;
	}
	if(f==1){
		long long cnt=0,ans=0;
		cnt++;
		m-=cnt;
		while(m>=0){
			ans++;
			cnt++;
			m-=cnt;
		}
		cout<<min(ans+1,n);
		return 0;
	}
	if(g==1){
		long long cnt=0,ans=0;
		cnt+=cha;
		m-=cnt;
		while(m>=0){
			ans++;
			cnt+=cha;
			m-=cnt;
		}
		cout<<min(ans+1,n);
		return 0;
	}
	for(int i=2;i<=n;i++){
		long long tg=a[i],sum=m,cnt=0;
		for(int j=i;j>=1;j--){
			if(sum>=tg-a[j]){
				sum-=(tg-a[j]);
				cnt++;
			}
			else break;
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}
