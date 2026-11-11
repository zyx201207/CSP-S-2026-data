#include<bits/stdc++.h>
using namespace std;
int n;
long long num,mid,ans,cnt=0,sum;
char c[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c1;
		cin>>num>>c1;
		sum+=num;
		for(int j=1;j<=num;j++){
			c[++cnt]=c1;
		}
	}
	mid=(sum+1)/2;
	for(int i=1,j=sum;i<=mid&&j>=mid;i++,j--){
		if(c[i]!=c[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
