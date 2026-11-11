#include<bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long ll;
int n,cnt;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int p;
		char x;
		cin>>p>>x;
		for(int j=1;j<=p;j++){
			c[++cnt]=x;
		}
	}
	int ans=0;
	int k=cnt>>1;
	for(int i=1;i<=k;i++){
		if(c[i]!=c[cnt-i+1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
