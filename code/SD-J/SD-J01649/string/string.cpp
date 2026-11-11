#include<bits/stdc++.h>
using namespace std;
int n,b[200010],l,r;
long long ans;
char s[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>s[i];
	}l=1,r=n;
	while(l<r){
		if(b[l]>b[r]){
			if(s[l]!=s[r]){
				ans+=b[r];
			}b[l]-=b[r],r--;
		}else if(b[l]<b[r]){
			if(s[l]!=s[r]){
				ans+=b[l];
			}b[r]-=b[l],l++;
		}else{
			if(s[l]!=s[r]){
				ans+=b[l];
			}l++,r--;
		}
	}cout<<ans;
	return 0;
}
