#include<bits/stdc++.h>
using namespace std;
int a[100005];
char c[2000005];
int main(){
//	freopen("string.in","r",srdin);
//	freopen ("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=c[1]){
			cnt+=a[i];
		}
	}
	cout<<cnt;

	return 0;

}
