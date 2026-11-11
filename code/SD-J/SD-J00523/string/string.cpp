#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005],s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		if(b[1]==b[2])cout<<0;
		else cout<<min(a[1],a[2]);
	}else{
		int r=0,ans=0,l=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				r++;
				s[r]=b[i];
			}
		}while(l<=r){
			if(s[l]!=s[r])ans++;
			l++;r--;
		}cout<<ans;
	}
	return 0;
}
