#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+100;
long long a[N],sum,ans;
char s[N];
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	
	int now=0,l=1,r=n;
	while(now<=sum/2&&l<r){
		if(l==r){
			break;
		}
		if(a[l]>a[r]){
			if(s[l]!=s[r]){
				ans+=a[r];
			}
			now+=a[r];
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
			if(s[l]!=s[r]){
				ans+=a[l];
			}
			now+=a[l];
			a[r]-=a[l];
			l++;
		}else{
			if(s[l]!=s[r]){
				ans+=a[l];
			}
			now+=a[l];
			l++,r--;
		}
	}
	cout<<ans;	
	return 0;
}

