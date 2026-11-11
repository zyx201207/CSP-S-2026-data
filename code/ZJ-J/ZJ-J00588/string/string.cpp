#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005],b1[400000005],b2[400000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long sum=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b1[sum]=c[i];
			sum++;
		}
	}
	for(int i=1;i<=sum;i++){
		b2[i]=b1[sum-i];
	}
	long long ans=0;
	for(int i=1;i<=sum;i++){
		if(b1[i]!=b2[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
