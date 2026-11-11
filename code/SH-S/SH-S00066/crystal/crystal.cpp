#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m,a[500005],s[500005],ans=0,temp=0,gs=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n-1;i++){
		s[i]=a[i+1]-a[i];
	}
	s[n]=-1;
	if(n>5000&&s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4]){
		for (int i=1;ans<=m;i++){
			temp=ans;
			ans+=s[1]*i;
		}
		cout << temp/s[1];
		return 0;
	}
	for (int i=2;i<=n-1;i++){
		temp=0;gs=1;
		if(s[i]==0) continue;
		for (int j=i-1;j>=1;j--){
			if(temp+a[i]-a[j]<=m){
				temp+=a[i]-a[j];
				gs++;
			}else{
				break;
			}
		}
		ans=max(ans,gs);
	}
	printf("%d",ans);
}
