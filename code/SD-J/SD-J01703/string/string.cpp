#include<bits/stdc++.h>
//TRICK||Treat! 
using namespace std;
int n;
long long a[200010];
char c[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if (n==1){
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	while (l<r){
		//cout<<a[l]<<c[l]<<" "<<a[r]<<c[r]<<" "<<l<<' '<<r<<endl;
		if (c[l]==c[r]){
			if (a[l]==a[r]){
				l++;
				r--;
			//	cout<<"!";
			}
			else if (a[l]>a[r]) {
				a[l]-=a[r];
				r--;
			//	cout<<"@";
			}
			else {
				a[r]-=a[l];
				l++;
			//	cout<<"#";
			}
		}	
		if (c[l]!=c[r]){
			if (a[l]==a[r]) {
				ans+=a[l];
				l++;
				r--;
			//	cout<<"$";
			}
			else if (a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			//	cout<<"^";
			}
			else {
				a[r]-=a[l];
				ans+=a[l];
				l++;
			//	cout<<"&";
			}
		}
		//cout<<a[l]<<c[l]<<" "<<a[r]<<c[r]<<" "<<l<<' '<<r<<endl<<endl;
	}
	cout<<ans;
	return 0;
}
