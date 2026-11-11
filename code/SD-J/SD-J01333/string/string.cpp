#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			sum++;
			s[sum]=c[i];
		}
	}
	int l=(1+cnt)/2,r=cnt/2+1,ans=0;
	while((l<=r)&&(l!=0)&&(r!=0)){
		if(s[l]!=s[r]){
			for(long long i=r;i<=cnt;i++)ans++;
			cout<<ans;
			return 0;
		}else{
			l--;r++;
		}
	}cout<<0;
	return 0;
} 
