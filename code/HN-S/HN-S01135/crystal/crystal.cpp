#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[50010];
long long ans;
bool cmp(int x,int y){
	return x<y;
}
//priority_queue<long long> qp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i<n;i++){
		a[i] = a[i+1]-a[i];
//		cout<<a[i]<<endl;
	}
	sort(a+1,a+1+n,cmp);
	if(a[n-1] == 0){
		cout<<n;
		return 0;
	}
	for(int i = 1;m>=0&&i<=n-1;i++){
//		cout<<a[i]<<endl;
		if(a[i] == 0&&i == 1){
			ans+=2;
			continue;
		}
		m-=a[i];
		if(m<=0){
			break;
		}
		ans++;
	}
	cout<<ans;
	return 0;
} 
