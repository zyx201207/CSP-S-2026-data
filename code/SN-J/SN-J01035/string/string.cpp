#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,a[N],ans=0;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	while(1){
		if(a[l]==0&&a[r]==0)break;
		int b=s[l]==s[r]?0:1;
		if(a[l]>a[r]){
			ans+=a[r]*b;
			a[l]-=a[r],a[r]=0;
			r--;
		}else if(a[l]==a[r]){
			ans+=a[l]*b;
			a[l]=0,a[r]=0;
			r--,l++;
		}else{
			ans+=a[l]*b;
			a[r]-=a[l],a[l]=0;
			l++;
		}
	}
	cout<<ans;
}
