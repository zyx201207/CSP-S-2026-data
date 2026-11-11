#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct node{
	int a;
	char c;
}t[200005];
ll sum;
ll ans;
signed main(){
  	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].a>>t[i].c;
		ans+=t[i].a;
	}
	ans/=2;	
	int l=1;
	int r=n;
	while(1){
		if(l==r) ans-=t[l].a/2;
		else if(l+1==r&&t[l].c==t[r].c) ans-=(t[l].a+t[r].a)/2;
		else if(t[l].c==t[r].c) ans-=min(t[l].a,t[r].a);
		if(t[l].a<t[r].a){
			t[r].a-=t[l].a;
			l++;
		}
		else if(t[l].a>t[r].a){
			t[l].a-=t[r].a;
			r--;
		}
		else l++,r--;
		if(l>r) break;
	}
	cout<<ans;
	return 0;
}
//jiu zhou you zai,shi wen shui zhu chen fu
//九州犹在，试问谁主沉浮 
