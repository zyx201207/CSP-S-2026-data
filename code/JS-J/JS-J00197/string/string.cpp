#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
struct s{
	long long sum;
	char x;
};
s a[N];
unsigned long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].x;
	}

	int l=1,r=n;

	while(l<r){
		if(a[l].x!=a[r].x){
			if(a[l].sum<a[r].sum){
				ans+=a[l].sum;
				a[r].sum-=a[l].sum;
				l++;
			}else{
				if(a[l].sum>a[r].sum){
					ans+=a[r].sum;
					a[l].sum-=a[r].sum;
					r--;
				}else{
					if(a[l].sum==a[r].sum){
						ans+=a[l].sum;
						l++;
						r--;
					}
				}

			}
		}else{
			if(a[l].sum<a[r].sum){
				a[r].sum-=a[l].sum;
				l++;
			}else{
				if(a[l].sum>a[r].sum){
					a[l].sum-=a[r].sum;
					r--;
				}else{
					if(a[l].sum==a[r].sum){
						l++;
						r--;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
