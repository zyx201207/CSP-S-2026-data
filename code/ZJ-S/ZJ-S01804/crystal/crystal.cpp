#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500005],b[500005];
int mx=-1,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int mm=m;
	for(int i=2;i<=n;i++){
		if(mm=0)continue;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int y=abs(b[i]-a[j]);
			if(mm>y){
				mm-=y;
				a[j]=b[i];
			}
		}
		for(int j=1;j<=n;j++){
			if(a[i]==a[j])cnt++;
			continue;
		}
		if(cnt>mx)mx=cnt-mx;
		for(int j=1;j<=n;j++){
			a[j]=b[j];
		}
		mm=m;
	}
	cout<<cnt;
	return 0;
}
