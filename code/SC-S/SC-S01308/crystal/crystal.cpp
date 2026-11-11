#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int a[N],n,m;
int sum=-1;
int ch(int x,int y,int l,int r){
	for(int i=1;i<=m;i++){
		if((x+i)%(l-r+1)==0&&(x+i)>=y*(l-r+1))return 1;
	}
	return 0;
}
int solve(){
	for(int i=1;i<=n;i++){
		int num=0;
		int r=i;
		for(int j=i+1;j<=n;j++){
			int l=j;
			num+=a[j];
			if(ch(num+a[i],a[j],l,r))sum=max(sum,l-r+1);
		} 
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n); 
	cout<<solve();
	return 0;
} 