#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
int n;
long long a[N];
char c[N];
string sum;
long long ans,he;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			sum+=c[i];
		}
		he+=a[i];
	}
	for(int i=0;i<he;i++){
		if(sum[i]!=sum[he-1-i]){
			ans++;
		}
		else{
			continue;
		}
	}
	cout<<ans/2;
	return 0;
}
