#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	long long l = 1,r=n,cnt=0;
	char x,y;
	while(l<=r){
		if(a[l]>0&&a[r]>0){
			if(c[l]!=c[r]){
				int q=min(a[l],a[r]);
				cnt+=q;
				a[l]-=q;
				a[r]-=q;
			}
			else if(c[l]==c[r]){
				int q=min(a[l],a[r]);
				a[l]-=q;
				a[r]-=q;
			}
		}
		if(a[l]<=0){
			if(l+1>r||a[l+1]==0)break;
			l++;
		}
		if(a[r]<=0){
			if(r-1<l||a[r-1]==0)break;
			r--;
		}
	}
	cout<<cnt;
	return 0;	
}