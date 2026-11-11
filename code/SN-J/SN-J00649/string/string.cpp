//黄伟豪 西安市铁一中学 SN-J00649 
#include<bits/stdc++.h>
using namespace std;
int n;
char s[200005];
int a[200005];
int main(){
	long long ans=0,len=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		len+=a[i];
	}
	int l=1,r=n;
	for(;l<r;){
		int z=min(a[l],a[r]);
		a[l]-=z;
		a[r]-=z;
		if(s[l]!=s[r]){
			ans+=z;
		}
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
	
