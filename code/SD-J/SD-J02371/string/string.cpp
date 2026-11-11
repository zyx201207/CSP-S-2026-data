#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n,a[N],ans=0,num=0;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>b[i];
		num+=a[i];
	}
	for(int i=1,j=n; i<=n; i++){
		while(a[i]){
			if(i>=j) break;
			if(a[i]>=a[j]){
//				cout<<11111<<endl;
				if(b[i]!=b[j]) ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
				j--;
			}else{
				if(b[i]!=b[j]) ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
			}
//			cout<<ans<<endl;
		}
//		cout<<i<<" "<<j<<" "<<a[j]<<endl;
		if(i>=j) break;
	}
	cout<<ans<<endl;
	return 0;
}
