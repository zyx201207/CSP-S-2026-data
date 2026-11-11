#include<bits/stdc++.h>
using namespace std;
struct st{
	long long lo;
	char le;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sl=0,nm=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].lo>>a[i].le;
		sl+=a[i].lo;
	}
	string x="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].lo;j++){
			x+=a[i].le;
		}
	}
	string y="";
	for(int i=n;i>=1;i--){
		for(int j=1;j<=a[i].lo;j++){
			y+=a[i].le;
		}
	}
	for(int i=1;i<=sl/2+1;i++){
		if(x[i-1]!=y[i-1]){
			y[i-1]=x[i-1];
			x[sl-i]=x[i-1];
			nm++;
		}
	}
	cout<<nm;
	return 0;
}
