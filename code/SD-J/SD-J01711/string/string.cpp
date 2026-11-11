#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,l=1,r;
long long cnt;
struct node{
	int x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].x,&a[i].c);
	}
	r=n;
	while(l<r) {
		if(a[l].x<=0) {
			l++;
			continue;
		}
		if(a[r].x<=0) {
			r++;
			continue;
		}
		if(a[r].x==a[l].x){
			if(a[l].c!=a[r].c) cnt+=a[l].x;
			l++;
			r--;
		}else{
			if(a[r].x<a[l].x){
				if(a[l].c!=a[r].c) cnt+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}else{
				if(a[r].c!=a[l].c) cnt+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
} 
