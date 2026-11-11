#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200009];
long long ans=0;
char s[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	while(l<r){
		if(s[l]!=s[r])	ans+=min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else if(a[l]==a[r]){
			l++,r--;
		}
		else{
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
