#include<bits/stdc++.h>
using namespace std;

struct st{
	int num;
	char c;
}a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long len=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].num>>a[i].c,len+=a[i].num;
	int l=1,r=n;
	long long ans=0;
	char lc,rc;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				a[r].num=0;
				r--;
			}else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}else{
				a[l].num=a[r].num=0;
				l++;
				r--;
			}
		}else{
			if(a[l].num>a[r].num){
				ans+=a[r].num;
				a[l].num-=a[r].num;
				a[r].num=0;
				r--;
			}else if(a[l].num<a[r].num){
				ans+=a[l].num;
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}else{
				ans+=a[r].num;
				a[l].num=a[r].num=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*4
1 a
2 b
1 c
1 a*/
