#include<bits/stdc++.h>
using namespace std;
long long d,a[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,x,ans=0,ans1=0,ans2=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			if(a[i+3]-a[i]>d&&a[i+3]-a[i+1]<=d&&a[i+2]-a[i]<=d){
				ans1=1;
				ans2=1;
				int j=i-2;
				while(j>0&&a[j+2]-a[j]>d&&a[j+1]-a[j]<=d){
					j--;
					ans1++;
				}
				j=i+5;
				while(j<=n&&a[j]-a[j-2]>d&&a[j]-a[j-1]<=d){
					j++;
					ans2++;
				}
				ans+=ans1*ans2;
			}
		}
		cout<<ans<<endl;//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
	}//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
	return 0;
}
