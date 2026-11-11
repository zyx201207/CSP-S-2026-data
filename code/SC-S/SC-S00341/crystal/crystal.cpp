#include<bits/stdc++.h>
using namespace std;
int n,mx=INT_MIN;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=2;i<=n;i++){
		long long t=m;
		int num=1,j=i-1;
		while(t&&j){
			if(t>=a[i]-a[j]){
				t-=a[i]-a[j];
				num++;
			}else break;
			j--;
			mx=max(mx,num);
		}
	}
	cout<<mx;
	return 0;
}