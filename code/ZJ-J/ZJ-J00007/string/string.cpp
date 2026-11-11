#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n,lst=0;
	while(i<j){
		if(c[i]!=c[j]){
			if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}else if(a[i]==a[j]){
				ans+=a[j];
				a[j]=a[i]=0;
				i++;
				j--;
			}else{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		}else{
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else if(a[i]==a[j]){
				a[j]=a[i]=0;
				i++;
				j--;
			}else{
				a[i]-=a[j];
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

