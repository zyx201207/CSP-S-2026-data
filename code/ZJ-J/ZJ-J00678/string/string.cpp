#include<bits/stdc++.h>
using namespace std;
struct node{
	int l;
	char a;
}a[200005];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].a;
	}
	int L=1,R=n;
	while(L<R){
		if(a[L].a==a[R].a){
			if(a[L].l<a[R].l){
				a[R].l-=a[L].l;
				L++;
			}
			else{
				if(a[L].l>a[R].l){
					a[L].l-=a[R].l;
					R--;
				}
				else{
					L++,R--;
				}
			}
		}
		else{
			if(a[L].l<a[R].l){
				a[R].l-=a[L].l;
				ans+=a[L].l;
				L++;
			}
			else{
				if(a[L].l>a[R].l){
					a[L].l-=a[R].l;
					ans+=a[R].l;
					R--;
				}
				else{
					ans+=a[L].l;
					L++,R--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}