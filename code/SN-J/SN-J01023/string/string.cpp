#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0,d=0,m=1e15*2;
char c[200005],b[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[j+d]=c[i];
		}
		d+=a[i];
	}
	for(int i=1;i<=d/2;i++){
		if(b[i]==b[d-i+1]){
			break;
		}
		else ans++;
	}
	cout<<ans;
	return 0;
}
