#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N],a1[N];
char c[N];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a1[i]=a[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	sum/=2;
	long long sum1=0;
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		sum1+=a[i];
		if(sum1>=sum){
			a[i]=a[i]-(sum1-sum);
			l=i;
			sum1=0;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		sum1+=a1[i];
		if(sum1>=sum){
			a1[i]=a1[i]-(sum1-sum);
			sum1=0;
			r=i;
			break;
		}
	}
	long long ans=0;
	int x=1,y=n;
	while(x<=l&&y>=r){
		if(a[x]==a1[y]){
			if(c[x]!=c[y])
				ans+=a[x];
			x++;
			y--;
			continue;
		}else if(a[x]>a1[y]){
			if(c[x]!=c[y]){
				ans+=a1[y];
			}
			a[x]-=a1[y];
			y--;
		}else if(a[x]<a1[y]){
			if(c[x]!=c[y])
				ans+=a[x];
			a1[y]-=a[x];
			x++;
		}
	}
	cout<<ans;
	return 0;
}