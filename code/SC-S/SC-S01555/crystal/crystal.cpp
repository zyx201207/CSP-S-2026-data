#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],q[500010],l,Max=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		q[i]=q[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(long long i=1;i<=n;i++){
		if(q[i]-q[l]-l*(a[i]-a[l])>m){
			while(q[i]-q[l]-l*(a[i]-a[l])>m){
				l++;
			}
			Max=max(Max,i-l);
		}
		else{
			Max=max(Max,i-l);
		}
	}
	cout<<Max;
	return 0;
}