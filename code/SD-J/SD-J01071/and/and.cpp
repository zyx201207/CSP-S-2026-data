#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],v[2000005],ans,t,ma,tong[10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	scanf("%d",a+i);
    	ma=max(ma,a[i]);
    	if(a[i]<=4)
    	tong[a[i]]++;
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			a[1]&=a[i];
		}
		cout<<a[1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
			ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;
	}
	if(ma<=4){
		if(tong[4]>=m)
		cout<<4;
		else if(tong[3]>=m)
		cout<<3;
		else if(tong[2]+tong[3]>=m)
		cout<<2;
		else
		cout<<1;
		return 0;
	}
	for(int i=n;i>=m;i--){
		t=a[i];
		for(int j=i;j>=i-m;j--){
			t&=a[j];
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}
