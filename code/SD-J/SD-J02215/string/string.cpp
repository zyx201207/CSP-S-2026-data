#include<iostream>
using namespace std;
int n,a[200005];
char s[200005];
long long maxx;
long long sum[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		maxx+=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(maxx%2==1){
		maxx=maxx/2+1;
	}else{
		maxx=maxx/2;
	}
	int ver; 
	for(int i=1;i<=n;i++){
		if(sum[i]>maxx){
			ver=i;
			break;
		}
	}
	long long ans=0;
	long long l=1,r=n;
	while(l<=ver&&r>=ver){
		if(a[l]>=a[r]&&s[l]!=s[r]){
			ans+=a[r];
			a[l]=a[l]-a[r];
			if(a[l]==0){
				l++;
			}
			r--;
		}else if(a[l]<=a[r]&&s[l]!=s[r]){
			ans+=a[l];
			a[r]=a[r]-a[l];
			if(a[r]==0){
				r--;
			}
			l++;
		}else if(a[l]>=a[r]&&s[l]==s[r]){
			a[l]=a[l]-a[r];
			if(a[l]==0){
				l++;
			}
			r--;
		}else if(a[l]<=a[r]&&s[l]==s[r]){
			a[r]=a[r]-a[l];
			if(a[r]==0){
				r--;
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
}
