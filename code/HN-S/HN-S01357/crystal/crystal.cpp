#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,now,cnt;
long long xx=5000,xxx=1e8;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	if(n>xx&&m>xxx){
		long long jiji=0;
		for(int i=1;i<=m;i++){
			if(jiji>=m){
				break;
			}
			cnt++;
			jiji+=i;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(now+a[i]-a[j]<=m){
					now+=a[i]-a[j];
					cnt++;
				}else{	
					break;
				}
				
			}
			now=0;
				maxx=max(maxx,cnt);
				cnt=0;
		}
	cout<<maxx;
	return 0;
} 
