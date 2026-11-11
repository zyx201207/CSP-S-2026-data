#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],b[9]={0},c[9]={0},d[9]={0},ma=-100000000;
int check(int x,int y){
	int cnt=7;
	while(x!=0){
		if(x%2!=0){
			b[cnt]=1;
		}
		x/=2;
		cnt--;
	}
	cnt=7;
	while(y!=0){
		if(y%2!=0){
			c[cnt]=1;
		}
		y/=2;
		cnt--;
	}
	for(int i=0;i<8;i++){
		
	}
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(check(a[i],a[j])>ma){
			}
		}
	}
}
