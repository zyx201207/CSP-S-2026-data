#include<bits/stdc++.h>
using namespace std;
#define N 500005

int n,m,ansm=0;
int ans[N]={1};
long long a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout);
	cin>>n>>m;
//	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);//从小到大 
	int m1=m;
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=m1){
				ans[i]++;
				m1-=a[i]-a[j];
//				cout<<"1"<<" "<<a[i]<<" "<<a[j]<<" "<<a[i]-a[j]<<" "<<m1<<" "<<ans[i]<<endl;
			}
			else {
//				cout<<"2"<<" "<<a[i]<<" "<<a[j]<<" "<<a[i]-a[j]<<" "<<m1<<" "<<ans[i]<<endl;
				break;
			}
		}
		m1=m;
	}
	for(int i=1;i<=n;i++) ansm=max(ansm,ans[i]);
	ansm+=1;
	cout<<ansm;
	return 0;
}
