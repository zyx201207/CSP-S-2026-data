#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,flag=1;
const int N=200005;
struct node{
	long long a;
	char b;
}x[N];
char y[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b;
		if((x[i].b!=x[i-1].b)&&(i-1)!=0)flag=0;
	}
	if(flag==1||n<=1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x[i].a;j++){
			y[cnt]=x[i].b;
			cnt++;
		}
	}
	int ans=0;
	for(int i=1;i<=cnt/2+1;i++){
		if(y[i]!=y[n-i+1]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
