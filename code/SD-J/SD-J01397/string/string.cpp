#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
ll n,a,ans,l=1;
char c;
struct link{
	ll sum;
	char s;
}p[200010],q[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(c==p[l-1].s){
			l--;
			p[l].sum+=a;
		}
		else{
			p[l].s=c;
			p[l].sum=a;
		}
		l++;
	}
	for(int i=1;i<l;i++){
		q[i]=p[l-i];
	}
	ll i=1,j=1;
	while(i<l&&j<l){
		if(p[i].s==q[j].s){
			if(p[i].sum==q[j].sum){
				i++,j++;
				continue;
			}
			if(p[i].sum>q[j].sum){
				p[i].sum-=q[j].sum;
				j++;
			}
			else{
				q[j].sum-=p[i].sum;
				i++;
			}
			continue;
		}
		if(p[i].sum==q[j].sum){
			ans+=p[i].sum;
			i++,j++;
			continue;
		}
		if(p[i].sum>q[j].sum){
			ans+=q[j].sum;
			p[i].sum-=q[j].sum;
			j++;
		}
		else{
			ans+=p[i].sum;
			q[j].sum-=p[i].sum;
			i++;
		}
	}
	cout<<ans/2;
	/*for(int i=1;i<l;i++){
		cout<<p[i].sum;
		for(int j=1;j<=p[i].sum;j++){
			cout<<p[i].s;
		}
	}*/
	return 0;
}
