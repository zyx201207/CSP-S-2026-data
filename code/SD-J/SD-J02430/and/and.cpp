#include<bits\stdc++.h>
using namespace std;
int a[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		sort(a,a+n+1,cmp);
		cout<<a[m-1];
		return 0;
	}
	if(n<=2000){
		if(m==1){
			int maxx=0;
			for(int i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
			}
			cout<<maxx;
			return 0;
		}
		if(m==n){
			int minn=1073741824;
			for(int i=1;i<=n;i++){
				minn=min(minn,a[i]);
			}
			cout<<minn;
			return 0;
		}
		if(m==2){
			int maxx=0,maxy=0;
			for(int i=1;i<=n;i++){
				maxy=maxx;
				maxx=(maxx,a[i]);
			}
			cout<<maxy;
		}
	}
	return 0;
}
