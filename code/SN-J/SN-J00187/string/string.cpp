#include<bits/stdc++.h>
using namespace std;
string q,w;
int a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long maxx=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>q[i];
		maxx+=a[i];
	}
	for(int i=1;i<=maxx/2;i++){
		for(int j=1;j<=n/2;j++){
			if(a[j]!=0){
				a[j]--;
				w=q[j];
				break;
			}
		}
		for(int j=n;j>=n/2;j--){
			if(a[j]!=0){
				a[j]--;
				if(w[0]!=q[j]){
					ans++;
				}
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
