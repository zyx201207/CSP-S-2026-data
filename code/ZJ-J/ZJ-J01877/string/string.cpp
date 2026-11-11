#include <iostream>
using namespace std;
const int maxn=2e5+10; 
int n;
int a[maxn];
char c[maxn];
long long len=0;
char c1,c2;
int a1,a2;
long long ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int i=1,j=n;
	c1=c[1];
	c2=c[n];
	a1=a[1];
	a2=a[n];
	while(i<j){
		if(a1>=a2){
			if(c1!=c2) ans+=a2;
			a1-=a2;
			a2=0;
		}else{
			if(c1!=c2) ans+=a1;
			a2-=a1;
			a1=0;
		}
		if(a1==0){
			i++;
			a1=a[i];
			c1=c[i];
		}
		if(a2==0){
			j--;
			a2=a[j];
			c2=c[j];
		}
	}
	cout<<ans;
}
