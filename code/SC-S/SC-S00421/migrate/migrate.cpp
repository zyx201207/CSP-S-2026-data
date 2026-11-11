#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],f=1,cha,cnt,ans;
void A(){
	cha=a[2]-a[1];
	for (int i=2;i<=n;i++)
		if(a[i]-a[i-1]!=cha) f=0;
	if(f==1){
		if(d<3*cha&&d>=2*cha) ans+=n-3;
		if(d>=3*cha||d<2*cha) ans+=0;
	}
}
void B(){
	if(f==0){
		for (int i=1;i<=n;i++){
			cnt=0;
			while(a[i]-a[1]<=d&&a[n]-a[i]<=d){
				i++;
				cnt++;
			}
			if(cnt==2){
				ans+=1;
				return;
			}
		}
        ans+=0;
	}
}
int wuguilv(){
	if(f==0&&ans!=n-3)
		for (int i=4;i<=n;i++){
			if(a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d&&a[i]-a[i-1]<=d&&a[i-2]-a[i-3]<=d) ans++;
		}
	cout<<ans;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		    cin>>a[i];
		A();
		B();
		wuguilv();
		f=1;
		ans=0;
	}
	return 0;
}