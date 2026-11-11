#include<bits/stdc++.h>
using namespace std;
int m,n,max0,max1,cnt;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>a[1];
	cnt=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(max0<a[i])
			max0=a[i],max1=i;
		cnt&=a[i];
	}
	if(m==1){
		cout<<max0;
		return 0;
	}
	if(m==n){
		cout<<cnt;
		return 0;
	}cnt=0;
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt<(a[i]&a[j]))
					cnt=(a[i]&a[j]);
	}
	cout<<cnt;
	return 0;
}
