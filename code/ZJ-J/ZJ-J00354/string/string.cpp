#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int a;
	char cc;
}f[200005];
int l,r;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	l=1;
	for(int i=1;i<=n;i++){
		cin>>f[i].a>>f[i].cc;
	}
	int ans=0;
	while(l<=r){
		if(l>r){
			break;
		}
		if(f[l].a>f[r].a){
			if(f[l].cc==f[r].cc){
				f[l].a-=f[r].a;
				r--;
			}else{
				ans+=f[r].a;
				f[l].a-=f[r].a;
				r--;
			}
		}else if(f[l].a<f[r].a){
			if(f[l].cc==f[r].cc){
				f[r].a-=f[l].a;
				l++;
			}else{
				ans+=f[l].a;
				f[r].a-=f[l].a;
				l++;
			}
		}else{
			if(f[l].cc==f[r].cc){
				l++;
				r--;
			}else{
				ans+=f[l].a;
				l++;
				r--;
			}
		}
	}
	cout<<ans;	
	return 0;
}

