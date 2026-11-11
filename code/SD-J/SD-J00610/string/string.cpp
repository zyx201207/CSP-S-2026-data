#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
long long a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}
	int left_pos=1,right_pos=n,ans=0;
	while(left_pos<=right_pos){
		if(c[left_pos]!=c[right_pos]){
			if(a[left_pos]==a[right_pos]){
				ans+=a[left_pos];
				++left_pos;
				--right_pos;
			}else if(a[left_pos]<a[right_pos]){
				ans+=a[left_pos];
				a[right_pos]-=a[left_pos];
				++left_pos;
			}else{
				ans+=a[right_pos];
				a[left_pos]-=a[right_pos];
				--right_pos;
			}
		}else{
			if(a[left_pos]==a[right_pos]){
				++left_pos;
				--right_pos;
			}else if(a[left_pos]<a[right_pos]){
				a[right_pos]-=a[left_pos];
				++left_pos;
			}else{
				a[left_pos]-=a[right_pos];
				--right_pos;
			}
		}
	}cout<<ans;
	return 0;
}
