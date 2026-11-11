#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,a[200005],b=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b+=a[i];
	}
	b/=2;
	int l=1,r=n;
	while(b){
		if(c[l]==c[r]){
			b-=min(a[l],a[r]);
			if(b<=0)break;
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[r]>a[l]){
				a[r]-=a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(b-min(a[l],a[r])<=0){
				cnt+=b;
				break;
			}
			cnt+=min(a[l],a[r]);
			b-=min(a[l],a[r]);
		}
	}
	cout<<cnt;
	return 0;
} 
