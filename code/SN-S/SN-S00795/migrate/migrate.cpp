#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[20000005];
int wow(int w,int end,int f) {
	int soans=0;
	int ffz=0;
	queue<int> q;
	if(w==end){
		return 1;
	}
	for(int i=w; i<=end; i++) {
		
		if(abs(a[w]-a[i])<m) {
			q.push(i);
			f++;
		}
	}
	f*=ffz;
    int ffff=0;
	for(int i=1;i<=ffz;i++){
		
	ffff+=wow(q.front(),end,f);
		q.pop();
	}
	return ffff;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int x=1;x<=n;x++){
		cin>>n>>m;
	int sum;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n-1; i++) {
		for(int j=i+1; j<=n; j++) {

			int ans=wow(i,j,1);
			if(ans==2) {
				sum++;
			}
		}
	}
	cout<<sum;
	}
	
	return 0;
}
