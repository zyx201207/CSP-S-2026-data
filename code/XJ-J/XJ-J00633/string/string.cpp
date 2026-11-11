#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}a[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		for(int j=1;j<=a[i].a ;j++){
			c[++cnt]=a[i].c;
		}
	}
	int cnt1=0;
	for(int i=1;i<=cnt/2;i++){
		if(c[i]!=c[cnt-i+1]){
			cnt1++;
			cout<<c[i]<<" "<<c[cnt-i+1]<<" "<<cnt-i+1<<" "<<cnt1<<"\n";
		}
	}
	cout<<cnt1;
	return 0;
}