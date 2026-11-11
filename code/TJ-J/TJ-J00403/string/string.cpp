#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int sz;
	char f;
}a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int sum=0;
	for (int i=1;i<=n;i++){
		cin >> a[i].sz >> a[i].f;
		sum+=a[i].sz;
	}
	sum=sum/2;
	int l=1,r=n,tg=0;
	int ans=0;
	while (l<=r && tg<sum){
		if (tg==sum){
			break;
		}
		if (a[l].f!=a[r].f){
			if (a[l].sz<=a[r].sz){
				if (tg+a[l].sz<=sum){
					tg+=a[l].sz;
					ans+=a[l].sz;
					a[r].sz-=a[l].sz;
					if (a[r].sz==0){
						r--;
					}
				}
				else{
					ans+=(sum-tg);
					tg=sum;
				}
				l++;
			}
			else{
				if (tg+a[r].sz<=sum){
					tg+=a[r].sz;
					ans+=a[r].sz;
					a[l].sz-=a[r].sz;
				}
				else{
					ans+=(sum-tg);
					tg=sum;
				}
				r--;
			}
		}
		else{
			if (a[l].sz<=a[r].sz){
				if (tg+a[l].sz<sum){
					tg+=a[l].sz;
					a[r].sz-=a[l].sz;
					if (a[r].sz==0){
						r--;
					}
				}
				else{
					tg=sum;
				}
				l++;
			}
			else{
				if (tg+a[r].sz<sum){
					tg+=a[r].sz;
					a[l].sz-=a[r].sz;
				}
				else{
					tg=sum;
				}
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
