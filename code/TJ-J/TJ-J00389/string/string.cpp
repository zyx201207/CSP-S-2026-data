#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int p,x;
	char c;
}a[100007];
int cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sz=0;
	while(n--){
		int x;
		char c;
		cin>>x>>c;
		a[++cnt]={sz+1,x,c};
		sz+=x;
	}
	int mid=0;
	for(int i=1;i<=cnt;i++){
		if(a[i].p>(sz+1)/2)mid=i-1;
	}
	if(!mid)mid=cnt;
	int p1=1,i1=1,p2=sz,i2=cnt;
	int ans=0;
	while(p1<=(sz+1)/2&&p2>(sz+1)/2){
		if(i1==i2)break;
		if(a[i1].c!=a[i2].c){
			ans+=min(a[i1].x,a[i2].x);
			if(a[i1].x<a[i2].x){
				p1+=a[i1].x;
				p2-=a[i1].x;
				a[i2].x-=a[i1].x;
				i1++;
			}else if(a[i1].x==a[i2].x){
				p1+=a[i1].x;
				p2-=a[i1].x;
				i1++;i2--;
			}else{
				p1+=a[i2].x;
				p2-=a[i2].x;
				a[i1].x-=a[i2].x;
				i2--;
			}
		}else{
			if(a[i1].x<a[i2].x){
				p1+=a[i1].x;
				p2-=a[i1].x;
				a[i2].x-=a[i1].x;
				i1++;
			}else if(a[i1].x==a[i2].x){
				p1+=a[i1].x;
				p2-=a[i1].x;
				i1++;i2--;
			}else{
				p1+=a[i2].x;
				p2-=a[i2].x;
				a[i1].x-=a[i2].x;
				i2--;
			}
		}
	}
	cout<<ans;
	return 0;
}

