#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans,t;
char s[200005],sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> s[i];
	}
	int l,r,mid=0;
	l=1,r=n;
	while(l<=r){
		if(mid ==0){
			if(s[l] == s[r]){
				if(a[l]>a[r]){
					t=a[l]-a[r],sum=s[l],mid=1;
				}
				else{
					t=a[r]-a[l],sum=s[r],mid=2;
					if(a[l] == a[r]) sum='0',mid=0;
				}
			}
			else{
				if(a[l]>a[r]){
					t=a[l]-a[r],sum=s[l],ans+=a[r],mid=1;
				}
				else {
					t=a[r]-a[l],sum=s[r],ans+=a[l],mid=2;
					if(a[l] == a[r]) sum='0',mid=0;
				}
			}
			l++,r--;
		}
		else if(mid==1){
			if(s[r] == sum){
				if(a[r] >t){
					sum=s[r],t=a[r]-t,mid=2;
				}
				else{
					t=t-a[r],mid=1;
					if(a[r]== t) sum='0',mid=0;
				}
			}
			else{
				if(a[r]>t){
					sum=s[r],ans+=t,t=a[r]-t,mid=2;
				}
				else{
					ans+=t,t=t-a[r],mid=1;
					if(a[r] == t) mid=0,sum='0';
				}
			}
			r--;
		}
		else if(mid == 2){
			if(s[l] == sum){
				if(a[l] >t){
					sum=s[l],t=a[l]-t,mid=1;
				}
				else{
					t=t-a[l],mid=2;
					if(a[l]== t) sum='0',mid=0;
				}
			}
			else{
				if(a[l]>t){
					sum=s[l],ans+=t,t=a[l]-t,mid=1;
				}
				else{
					ans+=t,t=t-a[l],mid=2;
					if(a[l] == t) mid=0,sum='0';
				}
			}
			l++;
		}

	}
	cout << ans << endl;
	return 0;
}
