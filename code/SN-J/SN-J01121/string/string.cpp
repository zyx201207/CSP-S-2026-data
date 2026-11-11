#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],c[N];
string res;
int len;
int ans; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];j++) res+=c[i];
	}
	int l=0,r=len-1;
	while(l<r){
		if(res[l]!=res[r]) ans++;
		l++; r--; 
	} 
	cout<<ans<<"\n";
	stdin.fclose();
	stdout.fclose();
	return 0;
}
