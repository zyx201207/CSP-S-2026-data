#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	LL i=1,j=n,ans=0;
	while (i<j){
		if (c[i]==c[j]){
			if (a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if (a[i]==a[j]){
				i++,j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}else{
			if (a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}else if (a[i]==a[j]){
				ans+=a[j];
				i++,j--;
			}else{
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}

