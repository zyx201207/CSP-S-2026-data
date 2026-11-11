//heyuanwei xiantieyizhongxue SN-J00705 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
string c;
ll n,a[maxn];
ll ans;
int main(){
	freopen("string6.in","r",stdin);
	freopen("string6.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	ll sl=a[l],sr=a[r];
	while(l!=r){
		if(sl>sr){
			sl-=sr;
			if(c[l]!=c[r])ans+=sr;
			sr=a[--r];
		}else if(sl==sr){
			if(c[l]!=c[r])ans+=sl;
			l++;
			if(l==r)break;
			r--;
			if(l==r)break;
			sl=a[l];
			sr=a[r];
		}else{
			sr-=sl;
			if(c[l]!=c[r])ans+=sl;
			sl=a[++l];
		}
	}
	cout<<ans<<endl;
	return 0;
}
