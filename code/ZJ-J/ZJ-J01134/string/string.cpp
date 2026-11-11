#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans,add,n;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		add+=a[i];
	}
	int l=1,r=n,m=0;char s;
	while(l<r){
		if(m==0){
			if(c[l]==c[r]){
				m=a[l]-a[r];
				s=c[l];
				if(m>0)r--;
				if(m<0)l++;
				if(m==0)l++,r--;
			}
			else{
				m=a[l]-a[r];
				ans+=min(a[l],a[r]);
				if(m<0)s=c[r],l++;
				if(m>0)s=c[l],r--;
				if(m==0)l++,r--;
			}
		}
		else{
			if(c[l]==c[r]){
				if(m>0)m-=a[r];
				else m+=a[l];
				if(m>0)r--;
				if(m<0) l++;
				if(m==0)l++,r--;
				s=c[l];
			}
			else{
				int x=m;
				if(m>0)m-=a[r];
				else m+=a[l];
				if(x>0){
					if(m>=0)ans+=a[r];
					else ans+=abs(x);
				}
				else{
					if(m<=0)ans+=a[l];
					else ans+=abs(x);
				}
				if(m>0)s=c[l],r--;
				if(m<0) s=c[r],l++;
				if(m==0)l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
//ddddddsssffffffrrr r rrrffffffsssdddddddd                               
//ddddddsssffffffrrrr rrrrffffffsssddddddd
