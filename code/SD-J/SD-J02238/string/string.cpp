#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[201010];
char c[201010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];	
	}
	for(int i=1;i<=n;i++){
		int ab=min(a[i],a[n-i+1]); 
		if(c[i]!=c[n-i+1]){
			cnt+=ab;
		}
		if(a[i]>=a[n-i+1]){
			int l=a[i]-a[n-i+1];
			if(c[n-i]!=c[i]){
				cnt+=l;
			}
			a[n-i]-=l;
		}else{
			int l=a[n-i+1]-a[i];
			if(c[i+1]!=c[n-i+1]){
				cnt+=l;
			}
			a[i+1]-=l;
		}
	}
	cout<<cnt/2;
	return 0;
}
