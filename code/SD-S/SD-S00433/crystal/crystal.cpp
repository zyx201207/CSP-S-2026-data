#include <bits/stdc++.h>

using namespace std;
const int N=5e5+5;
int n,m,a[N];
int cha,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	cha=abs(a[2]-a[1]);
	int res=cha;
	for(int i=3;i<=n;i++){
		cin>>a[i];
		res=abs(a[i]-a[i-1]);
	}
	if(res==cha){
		int s=m;
		if(a[2]-a[1]==1){
			for(int i=0;i<n;i++){
				if(s<i){
					break;
				}
				else {
					s-=i;
					ans++;
				}
			}
			cout<<ans<<"\n";
			return 0;
		}
		else {
			sort(a+1,a+n+1);
			if(a[2]-a[1]>=0){
				if(cha==0){
					cout<<"0\n";
					return 0;
				}
				for(int i=0;i<n;i+=cha){
					if(s<i){
						break;
					}
					else {
						s-=i;
						ans++;
					}
				}
				cout<<ans<<"\n";
			}
		}
	}
	else {
		sort(a+1,a+n+1);
		int s=m,tot=0;
		for(int i=1;i<=n;i++){
			int lv=a[i];
			for(int j=i-1;j>=1;j--){
				if(s<lv-a[j]){
					break;
				}
				else {
					s-=lv-a[j];
					tot++;
				}
			}
			ans=max(ans,tot);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
