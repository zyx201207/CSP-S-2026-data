#include<bits/stdc++.h>
using namespace std;
const int MA=2e5+100;
long long x[MA];
char a[MA+1000];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&x[i],&a[i]);
	}

	int l=1,r=n;
	while(l>=1 && l<=r && r<=n){
		if(a[l]==a[r]){
			if(x[l]>=x[r]){
				x[l]-=x[r];
				x[r]=0;
				r--;
				if(x[l]==0){
					l++;
				}
//				cout<<"____"<<"l="<<l<<"     r="<<r<<"ans="<<ans<<endl;
//				for(int i=1;i<=n;i++)
//					cout<<x[i]<<" "<<a[i]<<endl;
//				cout<<"_____"<<endl;
			}
			else{
				x[r]-=x[l];
				x[l]=0;
				l++;
				if(x[r]==0){
					r--;
				}
//				cout<<"____"<<"l="<<l<<"     r="<<r<<"ans="<<ans<<endl;
//				for(int i=1;i<=n;i++){
//					cout<<x[i]<<" "<<a[i]<<endl;
//				}
//				cout<<"_____"<<endl;
			}
		}
		else{
			if(x[l]>x[r]){//111233
				ans+=x[r];
				a[r]=a[l];
				x[l]-=x[r];
				r--;
				if(x[l]==0){
					l++;
				}
//				cout<<"____"<<"l="<<l<<"     r="<<r<<"ans="<<ans<<endl;
//				for(int i=1;i<=n;i++){
//					cout<<x[i]<<" "<<a[i]<<endl;
//				}
//				cout<<"_____"<<endl;
			}
			else{
//				cout<<"*****";
				ans+=x[l];
				a[l]=a[r];
				x[r]-=x[l];
				l++;
				if(x[r]==0){
					r--;
				}
//				cout<<"____"<<"l="<<l<<"     r="<<r<<"ans="<<ans<<endl;
//				for(int i=1;i<=n;i++){
//					cout<<x[i]<<" "<<a[i]<<endl;
//				}
//				cout<<"_____"<<endl;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);

	return 0;
}
