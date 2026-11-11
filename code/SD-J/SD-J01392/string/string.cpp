#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct as{
	long long x;
	int y;
};
int n;
as a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i =1;i<=n;i++){
		char s;
		scanf("%d %s",&a[i].x,&s);
		a[i].y=(int)s-'a';
	}
	int l=1,r=n,l1=0,r1=0;
	long long ans=0;
	while(l<r){//cout<<l<<" "<<r<<endl;
		if(a[l].x==a[r].x){
			if(a[l].y!=a[r].y){
				ans+=a[l].x;
			}
			l++,r--;			
		}else if(a[l].x>a[r].x){
			if(a[l].y!=a[r].y){
				ans+=a[r].x;
			}
			a[l].x-=a[r].x;
			r--;
			
		}else{
			if(a[l].y!=a[r].y){
				ans+=a[l].x;
			}
			a[r].x-=a[l].x;
			l++;
		}
		
	}
	printf("%lld\n",ans);
	return 0;
}
