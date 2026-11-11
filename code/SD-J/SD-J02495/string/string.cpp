#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,head,tail;
ll a[200002],ans;
char c[200002];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	head=1;
	tail=n;
	for(int i=1;i<n;i++){
		if(a[head]>a[tail]){
			if(c[head]!=c[tail]){
				ans+=a[tail];
			}
			a[head]-=a[tail];
			tail--;
		}
		else{
			if(c[head]!=c[tail]){
				ans+=a[head];
			}
			a[tail]-=a[head];
			head++;
		}
	}
	cout<<ans;
	return 0;
} 
