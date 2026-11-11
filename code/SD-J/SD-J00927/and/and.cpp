#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int mxid,mnid;
long long mxx=-1;
long long mnn=1e9+5;
long long ans;
long long a[N];
int flag;
int num1,num2,num3;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==3){
			num3++;
		}
		if(a[i]==2){
			num2++;
		}
		if(a[i]==1){
			num1++;
		}
		if(a[i]>4){
			flag=1;
		}
		ans&=a[i];
		if(a[i]>mxx){
			mxx=a[i];
			mxid=i;
		}
		if(a[i]<mnn){
			mnn=a[i];
			mnid=i;
		}
	}
	if(m==1){
		cout<<a[mxid];
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(m==2){
		int fians=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&(a[i]&a[j])>fians){
					fians=a[i]&a[j];
				}
			}
		}
		cout<<fians;
		return 0;
	}
	if(flag==0){
		if(num3>=m){
			cout<<3;
		}
		else if(num3+num2>=m){
			cout<<2;
		}
		else if(num1+num3>=m){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	int y;
	for(int i=n;i>=n-m+1;i++){
		if(y==0) y=a[i];
		else y&=a[i];
	}
	cout<<y;
	return 0;
}
