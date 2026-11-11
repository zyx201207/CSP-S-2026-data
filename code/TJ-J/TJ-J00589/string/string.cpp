#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+3;
struct yu {
	int l;
	char c;
}a[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].c;
	}int ln;
	char c;
	int l=1,r=n;
	while(l<r){
		if(a[l].l>a[r].l){
			a[l].l=a[l].l-a[r].l;
			if(a[l].c!=a[r].c)ans+=a[r].l;
			r--;
		}else if(a[r].l>a[l].l){
			a[r].l-=a[l].l;
			if(a[l].c!=a[r].c)ans+=a[l].l;
			l++;
		}else{
			if(a[l].c!=a[r].c){
				ans+=a[l].l;
			}
			l++,r--;
		}
	}cout<<ans;
	return 0;
}

