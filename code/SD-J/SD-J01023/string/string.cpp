#include<bits/stdc++.h>
using namespace std;

struct node{
	long long gs;
	char zm;
}a[200005];

long long cnt1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].gs>>a[i].zm;
		cnt1+=a[i].gs;
	}
	long long r=n;
	long long l=1;
	long long cnt=0;
	while(r>=l){
		int maxn=max(a[l].gs,a[r].gs);
		if(a[r].gs==a[l].gs && a[r].zm==a[l].zm){
			r--;
			l++;
		}else if(a[l].gs>a[r].gs && a[l].zm==a[r].zm){
			a[l].gs-=a[r].gs;
			r--;
		}else if(a[l].gs>a[r].gs && a[l].zm!=a[r].zm){
			cnt+=a[r].gs;
			a[l].gs-=a[r].gs;
			r--;
		}else if(a[l].gs<a[r].gs && a[r].zm==a[l].zm){
			a[r].gs-=a[l].gs;
			l++;
		}else if(a[l].gs<a[r].gs && a[l].zm!=a[r].zm){
			cnt+=a[l].gs;
			a[r].gs-=a[l].gs;
			l++;	
		}else if(a[l].gs==a[r].gs && a[l].zm!=a[r].zm){
			cnt+=a[l].gs;
			r--;
			l++;
		}
	}
	cout<<cnt;
	return 0;
} 
