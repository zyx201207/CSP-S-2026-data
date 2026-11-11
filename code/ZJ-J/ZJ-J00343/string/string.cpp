#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],a1[200010],s[200010],ans;
char c[200010],c1[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>a[1]>>c[1];
	for(int i=2;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			n--;
			i--;
		}
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		a1[i]=a[i];
		c1[i]=c[i];
	}
	if(s[n]%2==0){
		long long b;
		for(int i=1;i<=n;i++)
			if(s[i]>=s[n]/2){
				b=i;
				break;
			}
		if(s[b]!=s[n]/2){
			n++;
			for(int i=n;i>b+1;i--){
				a[i]=a[i-1];
				c[i]=c[i-1];
			}
			c[b+1]=c[b];
			a[b+1]=s[b]-s[n]/2;
			a[b]-=a[b+1];
		}
	}else{
		long long b;
		for(int i=1;i<=n;i++)
			if(s[i]>=s[n]/2){
				b=i;
				break;
			}
		if(s[b]!=s[n]/2){
			n++;
			for(int i=n;i>b+1;i--){
				a[i]=a[i-1];
				c[i]=c[i-1];
			}
			c[b+1]=c[b];
			a[b+1]=s[b]-s[n]/2;
			a[b]-=a[b+1];
			a[b+1]--;
		}
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				l++,r--;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++,r--;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}