#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,b;
struct mm{
	int x;
	char c;
}a[100005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		b+=a[i].x;
	}
	if((b+1)%2){
		cout<<b/2;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


