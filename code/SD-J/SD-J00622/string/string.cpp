#include<bits/stdc++.h>
using namespace std;
struct in{
	char c;
	long long t;
}a[200005];
int n;
long long cnt,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].t);
		cin>>a[i].c;
		sum+=a[i].t;
	}
	long long l=1,r=n;
	while(l<=r){
		if(a[l].t>a[r].t){
			if(a[l].c==a[r].c){
				a[l].t-=a[r].t;
			}
			else{
				a[l].t-=a[r].t;
				cnt+=a[r].t;
			}
			r--;
		}
		else if(a[l].t<a[r].t){
			if(a[l].c==a[r].c){
				a[r].t-=a[l].t;
			}
			else{
				a[r].t-=a[l].t;
				cnt+=a[l].t;
			}
			l++;
		}
		else{
			if(a[l].c!=a[r].c){
				cnt+=a[l].t;
			}
			l++,r--;
		}
	}
	printf("%lld",cnt);
	return 0;
} 
