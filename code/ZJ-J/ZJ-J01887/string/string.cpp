#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+7;
int a[N];
char s[N];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int total=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		total+=a[i];
	}
	int midpos1;
	midpos1=total/2;
	int nowposl=0;
	int nowposr=0;
	int l=1;
	int r=n;
	int ans=0;
	while(nowposl<midpos1){
		bool ok=true;
		if(nowposl+a[l]>midpos1){
			a[l]-=(midpos1-nowposl);
			nowposl=midpos1;
			ok=false;
		}
		else {
			nowposl+=a[l];
		}
		while(nowposr<nowposl){
			if(nowposr+a[r]>nowposl){
				a[r]-=nowposl-nowposr;
				if(s[r]!=s[l]){
					ans+=nowposl-nowposr;
				}
				nowposr=nowposl;
			}
			else{
				nowposr+=a[r];
				if(s[r]!=s[l]){
					ans+=a[r];
				}
				r--;
			}
		}
		if(ok) l++;
	}
	cout<<ans<<endl;
	return 0;
}
