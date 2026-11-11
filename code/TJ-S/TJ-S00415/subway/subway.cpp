#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int x1,x2,y1,y2;
	long long a[100005];
	long long b[100005];
	long long ak[100005];
	long long ak1[100005];
	for(int i=0;i<m;i++){
		cin>>a[i]; 
	} 
	for(int i=0;i<n;i++){
		cin>>b[i]; 
	} 
	for(int i=0;i<n+2;i++){
		cin>>ak[i];
	}
	for(int i=0;i<n+2;i++){
		cin>>ak1[i];
	}
	cin>>x1>>y1;
	cin>>x2>>y2;
	return 0;
} 
