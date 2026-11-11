#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int zhi,nex;
}a[500100];
int m,n;
int lst[500100],sm[500100];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i].zhi;
		a[i].nex=i+1;
	}
	for(int i=1;i<=m;i++){
		a[lst[a[i].zhi]].nex=i;
		lst[a[i].zhi]=i;
	}
	for(int i=m;i>=1;i--){
		if(a[a[i].nex].zhi==a[i].zhi) a[i].nex=a[a[i].nex].nex;
	}
	for(int i=1;i<=m;i++){
		int wz=i;
		while(wz<=m){
			if(a[wz].zhi!=a[a[wz].nex].zhi) sm[a[wz].zhi]++;
			wz=a[wz].nex;
		}
	}
	for(int i=1;i<n;i++){
		cout<<sm[i]<<" ";
	}
	cout<<sm[n];
}
