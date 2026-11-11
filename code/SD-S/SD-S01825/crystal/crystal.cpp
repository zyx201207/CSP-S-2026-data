//o(n方)+特判:75 
#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cha=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			flag=1;
		}
	}
	sort(a+1,a+1+n);
	if(flag==0){
		int l=0;
		int ans=0;
		int cnt=0;
		long long sum=0;
		while(sum<=m){
			ans++;
			sum+=l;
			if(ans%2==1){
				l+=cha;
			}
			cnt++;
		}
		if(sum>m){
			cnt--;
		}
		cout<<cnt;
		return 0;
	}
	//依次枚举以每个当基准能量 
	int maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[j]=a[i]-a[j];//与基准能量差 
		}
		long long sum=0;
		int l=1;
		int cnt=0;
		while(sum+b[l]<=m&&l<=i){
			sum+=b[l];
			l++;
			cnt++;
		}
		maxx=max(cnt,maxx);
	}
	cout<<maxx;
	return 0;
}
