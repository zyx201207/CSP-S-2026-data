#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char c;
}a[200010];
int k=0;
int n;
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		if(c==a[k].c&&k!=0){
			a[k].x+=x;
		}else{
			a[++k].c=c;
			a[k].x=x;
		}
	}
	int l=1,r=k;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].x>a[r].x){
				cnt+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}else if(a[l].x<a[r].x){
				cnt+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}else{
				cnt+=a[l].x;
				l++;
				r--;
			}
		}else{
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
