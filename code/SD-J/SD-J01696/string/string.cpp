#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int L=1,R=n;
	long long ans=0;
	while(L<R){
		if(c[L]!=c[R]){
			ans+=min(a[L],a[R]);
			if(a[L]<a[R]){
				a[R]-=a[L];
				L++;
			}else if(a[L]>a[R]){
				a[L]-=a[R];
				R--;
			}else{
				L++,R--;
			}
		}else{
			if(a[L]<a[R]){
				a[R]-=a[L];
				L++;
			}else if(a[L]>a[R]){
				a[L]-=a[R];
				R--;
			}else{
				L++,R--;
			}
		}
	}
	cout<<ans;
	return 0;
}
