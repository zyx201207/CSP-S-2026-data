#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans,cnt;
int a[200005];
char ch[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		cnt+=a[i];
	}
	int l1=1,h=1,l=n,r=cnt;
	while(l1<=r){
		if(a[h]==a[l]){
			if(ch[h]!=ch[l]){
				ans+=a[h];
			}
			h++;
			l--;
			l1+=a[h];
			r-=a[h];
			if(l1>r)break;
		}
		bool f=0;
		while(a[h]<=a[l]){
			if(ch[h]!=ch[l]){
				ans+=a[h];
			}
			l1+=a[h];
			r-=a[h];
			a[l]-=a[h];
			h++;
			if(l1>r||h>=l||l1>=(cnt+1)/2||r<=(cnt+1)/2){
				f=1;
				break;
			}
		}
		if(f==1){
			break;
		}
		while(a[h]>=a[l]){
			if(ch[h]!=ch[l]){
				ans+=a[l];
			}
			l1+=a[l];
			r-=a[l];
			a[h]-=a[l];
			l--;
			if(l1>=r||h>=l||l1>=(cnt+1)/2||r<=(cnt+1)/2){
				f=1;
				break;
			}
		}
		if(f==1){
			break;
		}
	}
	cout<<ans;
	return 0;
}