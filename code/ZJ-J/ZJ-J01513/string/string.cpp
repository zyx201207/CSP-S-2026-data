#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct point{
	int a;
	char c;
}a[N];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	int l=1,r=n,cha=0;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].a>a[r].a)a[l].a-=a[r].a,r--;
			else a[r].a-=a[l].a,l++;
			continue;
		}
		if(a[l].a>a[r].a){
			a[l].a-=a[r].a;
			ans+=a[r--].a;
		}
		else{
			a[r].a-=a[l].a;
			ans+=a[l++].a;
		}
	}
	cout<<ans;
	return 0;
}