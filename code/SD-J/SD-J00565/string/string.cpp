#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,a[N],ans,x;
string c[N],s[100000010];
int main(){
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s[x+j]=c[i];
		}
		x+=a[i];
	}
	for(int i=1;i<=x/2;i++){
		if(s[i]!=s[x-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
