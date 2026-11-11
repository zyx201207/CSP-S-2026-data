#include<bits/stdc++.h>
using namespace std;
int n,m,a[500081],k=1,nim=-1e6,ans,k2,d,xam=-1e6;
void a1(){
	int sum=0,cnt1=1;
	for(int i=1;;i++){
		sum+=i;
		if(sum>m||cnt1==n){
			break;
		}
		cnt1++;
	}
	if(cnt1==1){
		cout<<0;
	}else{
	cout<<cnt1;	
	}
}
void a2(){
	int sum=0,cnt1=1;
	for(int i=1;;i++){
		sum+=i*d;
		if(sum>m||cnt1==n){
			break;
		}
		cnt1++;
	}
	if(cnt1==1){
		cout<<0;
	}else{
	cout<<cnt1;	
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			k=-1;
		}
		if(i==2){
			d=a[2]-a[1];
		}
		if(a[i]-a[i-1]!=d&&i>=2){
			k2=-1;
		}
		nim=min(nim,a[i]);
		xam=max(xam,a[i]);
	}
	if(k==1){
		a1();
		return 0;
	}
	if(k2==0){
		a2();
		return 0;
	}
	if(m>=(xam-nim)*(n-1)){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=nim;i<=xam;i++){
		int cnt=0;
		int last,step=0;
		for(int f=1;f<=n;f++){
			if(a[f]>i){
				break;
			}
			last=f;
		}
		for(int f=last;f>=1;f--){
			step+=i-a[f];
			if(step>m){
				break;
			}
			cnt++;
		}
		if(cnt==1){
			cnt=0;
		}
		ans=max(ans,cnt);
		if(ans==n){
			break;
		}
	}
	cout<<ans;
	return 0;
}
