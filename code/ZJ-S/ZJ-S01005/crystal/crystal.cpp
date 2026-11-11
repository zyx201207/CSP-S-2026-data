#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],b[500005],mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		b[i]=a[i+1]-a[i];
		ll mm=m,sum=0,cnt=1;
		for(int j=i-1;j>=0;j--){
			sum+=b[j];
			if(mm>=sum){
				mm-=sum;
				cnt++;
			}else break;
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	return 0;
}