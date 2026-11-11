#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a[200005];
	long long ans=0;
	char b[200005];
	int c[100001];
	int d[100001];
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		a[i]=x;
		b[i]=y;
		for(int j=1;j<=a[i];j++){
			c[++ans]=b[i];
		}
	}
	for(int i=1;i<=ans/2+1;i++){
        d[i]=c[i];
        d[ans-i+1]=c[i];
	}
	long long cnt=0;
	for(int i=1;i<=ans;i++){
		if(d[i]!=c[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
