#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long sum;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i].sum>>a[i].c;
	long long ans=0;
	int L=1,R=n;
	while(L<R){
		if(a[L].c==a[R].c){
			if(a[L].sum>a[R].sum){
				a[L].sum-=a[R].sum;
				R--;
			}
			else if(a[L].sum<a[R].sum){
				a[R].sum-=a[L].sum;
				L++;
			}
			else{
				R--;
				L++;
			}
		}
		else{
			if(a[L].sum>a[R].sum){
				ans+=a[R].sum;
				a[L].sum-=a[R].sum;
				R--;
			}
			else if(a[L].sum<a[R].sum){
				ans+=a[L].sum;
				a[R].sum-=a[L].sum;
				L++;
			}
			else{
				ans+=a[L].sum;
				R--;
				L++;
			}
		}
	}
	cout<<ans;
	return 0;
}
