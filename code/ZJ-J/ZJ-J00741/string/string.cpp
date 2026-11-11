#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,len; 
	char d;
}a[1000001];
int np,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>np;
	for(int i=1;i<=np;i++){
		a[i].l=a[i-1].r+1;
		int x;
		cin>>x>>a[i].d;
		a[i].len=x;
		a[i].r=a[i].l+x-1;
	}
	int lq=1,rq=np;
	long long ans=0;
	while(lq<rq){
		if(a[lq].d!=a[rq].d){
			if(a[lq].len<a[rq].len){
				a[rq].len-=a[lq].len;
				ans+=a[lq].len;
				lq++;
			}
			else if(a[lq].len>a[rq].len){
				a[lq].len-=a[rq].len;
				ans+=a[rq].len;
				rq--;
			}
			else if(a[lq].len==a[rq].len){
				ans+=a[rq].len;
				rq--;
				lq++;
			}
		}else{
			if(a[lq].len<a[rq].len){
				a[rq].len-=a[lq].len;
				lq++;
			}
			else if(a[lq].len>a[rq].len){
				a[lq].len-=a[rq].len;
				rq--;
			}
			else if(a[lq].len==a[rq].len){
				rq--;
				lq++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
