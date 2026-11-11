#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,mm,cnt=0,maxx=INT_MIN;
	cin>>n>>mm;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>a[j]){
				int xx=a[i],yy=a[j];
				a[i]=yy;
				a[j]=xx;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int m=mm;
		for(int j=1;j<=n;j++){
			if(a[i]>=a[j]){
				int cha=a[i]-a[j];
				if(cha<=m){
					cnt++;
					m-=cha;
				}
			}
		}
		maxx=max(maxx,cnt);
		cnt=0;
	}
	cout<<maxx;
	return 0;
} 
