#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	srand(time(0));
	int t=clock();
	while(clock()-t<=0.9){
		for(int i=0;i<n;i++){
			swap(a[rand()%n],a[rand()%n]);
		}
		int cnt=a[0];
		for(int i=1;i<m;i++){
			cnt&=a[i];
		}
		ans=max(ans,cnt);
//		for(int i=0;i<n;i++){
//			cout<<a[i]<<' ';
//		}
//		cout<<endl;
	}
//	cout<<clock()-t<<' ';
	cout<<ans;
	return 0;
}
//*
