//SN-J00748  张哲瀚  西安市第八十九中学  
#include <bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int m=n;
	long long cnt=0;
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		if(b[n-i+y+1]!=b[i-x]){
			cnt+=min(a[i-x],a[n-i+y+1]);
		}
		if(a[i-x]>a[n-i+1+y]){
			a[i-x]-=a[n-i+y+1];
			x++;
		}
		else if(a[n-i+y+1]>a[i-x]){
			a[n-i+y+1]-=a[i-x];
			y++;
		}
		else{
			m--;
		}
	}
	cout<<cnt;
	return 0;
}
