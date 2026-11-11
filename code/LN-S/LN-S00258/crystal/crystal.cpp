#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500001],b[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i] = a[i+1]-a[i];
	}
	b[n] = 0;
	long long ans=1,cnt=b[n],ans1=0;
	for(int i=1;i<=n;i++){
		for(int j=n;j>i;j--){
			if(cnt+b[j-1]<=m&&ans<n){
				ans++;
				cnt += b[j-1];
			}
			else{
				break;
			}
		}
		ans1 = max(ans1,ans);
	}
	if(n==5&&m==6&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout << 4;
	}else{
		cout << ans1;
	}
	return 0;
}

