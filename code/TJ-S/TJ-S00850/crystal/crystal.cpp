#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxx=-1;
	bool b=1;
	cin>>n>>m;
	cin>>a[1];
	for(long long i=2;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
		if(a[i]!=a[i-1]){
			b=0;
		}
	}
	if(b==1){
		cout<<n<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long x=m,ans=0;
		for(long long j=i;j>=1;j--){
			if(x>=(s[i]-s[j])){
				x-=(s[i]-s[j]);
				s[j]+=(s[i]-s[j]);
			}
			else{
				break;
			}
		}
		for(long long j=1;j<=n;j++){
			if(s[j]==s[j+1]||s[j]==s[j-1]){
				ans++;
			}
		}
		for(long long j=1;j<=n;j++){
			s[j]=a[j];
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx<<endl;
	return 0;
}
