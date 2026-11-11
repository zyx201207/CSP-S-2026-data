#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ch{
	int l;
	char c;
}c[200010];
int n,zl,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].l>>c[i].c;
		zl+=c[i].l;
	}
	int l=1,r=n;
	while(l<r){
		if(c[l].c!=c[r].c){
			ans+=min(c[r].l,c[l].l);
			//cout<<l<<' '<<r<<' '<<c[l].l<<' '<<c[r].l<<' '<<ans<<'\n';
			if(c[l].l!=c[r].l){
				if(c[l].l<c[r].l){
					c[r].l-=c[l].l;
					l++;
				}
				else if(c[l].l>c[r].l){
					c[l].l-=c[r].l;
					r--;
				}
				
			}
			else{	
				l++;
				r--;
		    }
			
		}
		else{
			if(c[l].l!=c[r].l){
				if(c[l].l<c[r].l){
					l++;
					c[r].l-=c[l].l;
				}
				if(c[l].l>c[r].l){
					r--;
					c[l].l-=c[r].l;
				}
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}