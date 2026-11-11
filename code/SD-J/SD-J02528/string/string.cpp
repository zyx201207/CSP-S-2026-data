#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200010];
	char c[10000010];
	int sum=0;
	for(int i=1;i<=n;i++){
		 cin>>a[i]>>c[i];
	}
	for(int i=n;i>=2;i--){
		for(int j=i;j<=n;j++){
			c[i]++;
		}sum++;
	}
		cout<<sum;
	return 0;
}
