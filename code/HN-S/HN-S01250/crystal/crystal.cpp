#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=-1;
	int a[500010],b[500010],maax=-1000000,miin=1000000;
	cin >> n >> m;
	bool o=0,p=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i) o=1;
		if(i!=1&&i!=2&&abs(a[i]-a[i-1])!=abs(a[i-1]-a[i-2])) p=1;
		if(a[i]>maax) maax=a[i];
		if(a[i]<miin) miin=a[i];
	}
	if(o==0){
		long long cnt=0,num;
		for(int i=1;cnt<=m;i++){
			cnt+=i;
			num=i;
		}
		cout << num;
		return 0;
	}
	if(p==0){
		long long cnt=0,num=1;
		for(int i=a[2]-a[1];cnt<=m;i+=(a[2]-a[1])){
			cnt+=i;
			num++;
		}
		cout << num-1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int j=miin;j<=maax;j++){
		long long num=0,f=m;
		for(int i=1;i<=n;i++){
			if(a[i]<=j&&f>=(j-a[i])){
				f-=(j-a[i]);
				num++;
			}
		}
		if(ans<num) ans=num;
	}
	cout << ans;
	return 0;
} 
