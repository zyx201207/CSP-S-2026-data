#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
struct node{
	long long a;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].a==a[r].a&&a[l].c==a[r].c){
			l++;r--;
			continue;
		}
		if(a[l].c==a[r].c){
			if(a[l].a<a[r].a){
				a[r].a-=a[l].a;
				l++;
			}else{
				a[l].a-=a[r].a;
				r--;
			}
		}else{
			if(a[l].a<a[r].a){
				ans+=a[l].a;
				a[r].a-=a[l].a;
				l++;
			}else if(a[l].a==a[r].a){
				ans+=a[l].a;
				l++,r--;
			}else{
				ans+=a[r].a;
				a[l].a-=a[r].a;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

