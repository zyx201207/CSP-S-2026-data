#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans=0,sum=0;
char c[200005];
char s[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=sum;j>sum-a[i];j--){
			s[j]=c[i];
		}
	}
	for(int i=1;i<=sum/2;i++){
		if(s[sum+1-i]!=s[i]) ans++;
	}
	cout<<ans;
	return 0;
	
}
