#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500020],b[500020],ans,cnt,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int f=1,f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i<=2){
			f1=a[i]-a[i-1]; 
		}else if(a[i]-a[i-1]!=f1){
			f=0;
		}
	}
	if(f==1){
		for(int j=1;j<=n&&cnt<=m;j++){
			cnt+=(j-1)*(a[j]-a[j-1]);
			if(cnt<=m){
				sum++;
				ans=max(ans,sum);
			}
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			cnt=0;
			sum=0;
			for(int j=i;j<=n&&cnt<=m;j++){
				cnt+=(j-i)*(a[j]-a[j-1]);
				if(cnt<=m){
					sum++;
					ans=max(ans,sum);
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
