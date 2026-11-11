//SN-S00480 西安铁一中滨河高级中学 李明轩 
#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005];
long long anss;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	anss=0;
	for(long long i=n;i>0;i--){
		long long t=m,ans=0;
		if(a[i]==a[i+1]) {
			ans++;
			continue;
		}
		for(long long j=i;j>0;j--){
			long long s=a[j];
			if(t<=0) break;
			if(s==a[i]){
				ans++;
				continue;
			}
			else{
				int kkk=a[i]-s;
				t=t-kkk;
				if(t<=0) break;
				ans++;
			}
		}
		anss=max(ans,anss);
	}
	cout<<anss;
	return 0;
}
