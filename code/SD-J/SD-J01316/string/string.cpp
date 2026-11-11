#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN=200005;

int n,ops;
ll a[MAXN];
char c[MAXN];
ll sum;
ll ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i]; 
	}
	if(sum%2==1){
		ll temp=sum/2+1; 
		for(int i=1;i<=n;i++){
			if(temp>a[i]){
				temp-=a[i];
				continue;
			} else{
				ops=i;
				break;
			}
		}
		a[ops]--; 
	}
	
	
	int l=1,r=n;
	ll e=a[l],g=a[r];
	while(l<r){
		if(e<g){
			if(c[l]!=c[r])	ans+=e;
			g-=e;
			l++;
			e=a[l];
			
		}else if(e==g){
			if(c[l]!=c[r])	ans+=e;	
			l++;
			r--;
			e=a[l]; 
			g=a[r];
		}else{
			if(c[l]!=c[r])	ans+=g;
			e-=g;
			r--;
			g=a[r];
		}
	}
	cout<<ans;
	return 0;
}
