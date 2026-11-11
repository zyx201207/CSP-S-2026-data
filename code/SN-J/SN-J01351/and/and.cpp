#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int a[200005];
int b[200005];
int cnt=0;
int lb;
void qqq(int q,int w){
	if(w==0){
		int sum=b[1];
		for(int i=2;i<=m;i++){
			sum=sum&b[i];
		}
		cnt=max(cnt,sum);
	}else {
		for(int i=q+1;i<=n;i++){
			b[m-w+1]=a[i];
			qqq(i,w-1);
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[1]=a[i];
		qqq(i,m-1);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
