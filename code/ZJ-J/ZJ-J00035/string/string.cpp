#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,sum;
struct stu{
	int cnt;
	char wd;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].wd;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].wd!=a[r].wd){
			if(a[l].cnt<=a[r].cnt){
				a[r].cnt-=a[l].cnt;
				sum+=a[l].cnt;
				l++;
			}
			else{
				a[l].cnt-=a[r].cnt;
				sum+=a[r].cnt;
				r--;
			}
		}
		else{
			if(a[l].cnt<=a[r].cnt){
				a[r].cnt-=a[l].cnt;
				l++;
			}
			else{
				a[l].cnt-=a[r].cnt;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
