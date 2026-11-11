#include<bits/stdc++.h>
using namespace std;
long long a[50005],b[50005],ans[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		cout<<1;
		for(long long i=2;i<=m;i++)cout<<" "<<i;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		long long s[50005],js=1;
		for(long long j=i;j<=n;j++){
			s[js++]=a[j];
		}
		for(long long j=1;j<=n;j++){
			for(long long k=j;k<=n;k++){
				if(s[j]==s[k]&&s[j]!=0){
					for(long long f=j;f<k;f++){
						s[f]=0;
					}
				}
			}
			
		}
		for(long long j=1;j<=n;j++){
			if(s[j]!=0)ans[s[j]]++;
		}
	}
	cout<<ans[1];
	for(int i=2;i<=m;i++){
		cout<<" "<<ans[i];
	}
	return 0;
}
