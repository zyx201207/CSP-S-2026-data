#include<bits/stdc++.h>
#define int long long
struct st{
	int s;
	char c;
}a[200005];
int cnt;
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].s==a[r].s){
			if(a[l].c==a[r].c){
				l++,r--;
				continue;
			}else{
				cnt+=a[l].s;
				l++,r--;
				continue;
			}
		}
		else{
			if(a[l].c!=a[r].c){
				cnt+=min(a[l].s,a[r].s);
				if(a[l].s>a[r].s){
					a[l].s-=a[r].s;
					r--;
					continue;
				}else{
					a[r].s-=a[l].s;
					l++;
					continue;
				}
			}else{
				if(a[l].s>a[r].s){
					a[l].s-=a[r].s;
					r--;
					continue;
				}else{
					a[r].s-=a[l].s;
					l++;
					continue;
				}	
			}
		}
	}cout<<cnt;
	return 0;
} 
