#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans,l,k;
bool b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=n;
	k=(1<<30);
	for(int i=30;i>=0;i--){
		//cout<<k<<"\n";
		int li=0;
		for(int j=1;j<=n;j++){
			if(b[j]==0&&a[j]>=k){
				li++;
			}
			//cout<<"   "<<a[i]<<" "<<li<<"\n";
		}
		if(li>=m){
			ans+=k;
			for(int j=1;j<=n;j++){
				if(a[j]<k){
					b[j]=1;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j]>=k){
				a[j]-=k;
			}
		}
		k/=2;
	}
	cout<<ans;
	return 0;
}
