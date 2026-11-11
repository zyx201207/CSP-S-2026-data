#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n,m,s[35][N],b[100000000];
long long a[N];
long long num,cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]>=1){
			cnt=max(cnt,a[i]);
		}
		b[a[i]]++;
	}
	cout<<cnt;
} 
