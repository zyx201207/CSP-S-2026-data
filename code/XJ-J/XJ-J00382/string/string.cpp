#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],cnt,lens;
string c[N],s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=lens;j<lens+a[i];j++){
			s[j]=c[i];
		}
		lens+=a[i];
	}
	for(int i=0;i<lens;i++){
		if(i==lens-i-1){
			break;
		}
		if(s[i]!=s[lens-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}