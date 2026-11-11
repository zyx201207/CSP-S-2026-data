#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[10000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=a[2]-a[1];
		int ans=d/cnt;
		int qq=n/ans;
		int sum=0;
		int q[100005];
		for(int i=1;i<=100005;i++){
			q[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(i%ans==0&&i>2&&i/ans<=2){
				sum++;
				q[i]=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(q[i]!=0){
				sum+=n-q[i];
			}
		}
		
		cout<<sum<<endl;
	}
	return 0;
}
