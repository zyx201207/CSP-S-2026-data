#include<bits/stdc++.h>
using namespace std;
int n;
long long h;
int a[20005];
char b[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int x=1,y=n;
	while(x!=y&&x<y)
	{
		if(b[x]!=b[y]) h+=min(a[x],a[y]);
		if(a[x]<a[y]){
			a[y]-=a[x];
			x++;
			if(a[y]==0) y--;
		}
		else{
			a[x]-=a[y];
			y--;
			if(a[x]==0) x++;
		}
	}
	cout<<h;
	return 0;
}
