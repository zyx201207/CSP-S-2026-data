#include<bits/stdc++.h>
using namespace std;
long long a[20005],c[20005];
char b[20005],d[10000000005];
string s;
int u=1;
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	int n;
	cin>>n; 
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]; 
		sum+=a[i];
	}
	int u=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			d[u]=b[i];
			u++;
		}
	} 
	int ans=0;
	for(int i=1;i<=sum/2;i++){
		if(d[i]!=d[sum-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
