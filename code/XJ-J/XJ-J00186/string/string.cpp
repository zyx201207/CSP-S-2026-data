#include<bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long int ans=0;
	int i=n;
	int j=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	while(j<i){
		if(s[i]==s[j]){
			int minn=min(a[i],a[j]);
			a[i]-=minn;
			a[j]-=minn;
			if(a[i]==0){
				i--;
			}
			if(a[j]==0){
				j++;
			}
		}else{
			int minn=min(a[i],a[j]);
			ans+=minn;
			a[i]-=minn;
			a[j]-=minn;
			if(a[i]==0){
				i--;
			}
			if(a[j]==0){
				j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
