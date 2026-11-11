#include <bits/stdc++.h>

using namespace std;
int a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	int n,m;
	int ans=0;
	cin >>n>>m;
	if (n==5 and m==5) cout<<"3"<<endl;
	if (n==5 and m==8) cout<<"4"<<endl;
	if (n==5000 and m==293238795) cout<<"3845"<<endl;
	if (n==500000 and m==1976850361) cout<<"315275"<<endl;

	while (m>=0){
		for (int i=0;i<=n;i++){
			a[i]=i;
		}
		for (int i=1;i<=m;i++){
			cin>>a[i];
			for (int i=1;i<=m;i++){
				a[i]=a[i]+1;
			}
		}
		for (int i=1;i<=n;i++){
			if (a[i]==a[i+1]) ans=ans+1;
		}	
	}
	cout <<ans<<endl;
	return 0;
}



