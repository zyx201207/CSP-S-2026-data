#include<bits/stdc++.h>
using namespace std;

long long n,m,maxx,a[500005],f[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long cnt=0,mm=m;
		if(a[i]==a[i+1]) continue;
		for(int j=i;j>0;j--){
			long long c=a[i]-a[j];
			if(c<=mm){
				mm-=c;
				cnt++;
			}else continue;
		}
		maxx=max(cnt,maxx);
	}
	cout<<maxx;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
