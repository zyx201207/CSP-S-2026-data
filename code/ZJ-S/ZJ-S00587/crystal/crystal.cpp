#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1;
struct node{
	long long cnt=1,id=0,sc=0;
}f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f[1].cnt=1;
	f[1].id=1;
	f[1].sc=m;
	for(int i=2;i<=n;i++){
		if(f[i-1].sc>=(f[i-1].cnt)*(a[i]-a[i-1])){
			f[i].cnt=f[i-1].cnt+1;
			f[i].id=f[i-1].id;
			f[i].sc=f[i-1].sc-((f[i-1].cnt)*(a[i]-a[i-1]));
		}
		else{
			f[i].sc=f[i-1].sc;
			for(int j=f[i-1].id;;j++){
				f[i].sc+=a[i-1]-a[j];
				if(f[i].sc>=(i-1-j)*(a[i]-a[i-1])){
					f[i].sc-=(i-1-j)*(a[i]-a[i-1]);
					f[i].id=j+1;
					f[i].cnt=i-j;
					break;
				}
			}
		}
		ans=max(ans,f[i].cnt);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
