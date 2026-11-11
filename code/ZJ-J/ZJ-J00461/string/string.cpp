#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,len=0;
struct node{
	int a;
	char c;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		len+=a[i].a;
	}
	unsigned long long l=1,r=n,L=1,R=len;
	while(l<r){
		if(a[l].c==a[r].c){
			L+=min(a[l].a,a[r].a);
			R-=min(a[r].a,a[l].a);
			if(a[l].a>a[r].a){
				a[l].a-=a[r].a;
				a[r].a=0;
				r--;
			}else if(a[l].a<a[r].a){
				a[r].a-=a[l].a;
				a[l].a=0;
				l++;
			}else{
				a[r].a=0;
				a[l].a=0;
				l++;
				r--;
			}
		}else{
			L+=min(a[l].a,a[r].a);
			R-=min(a[r].a,a[l].a);
			if(a[l].a>a[r].a){
				a[l].a-=a[r].a;
				ans+=a[r].a;
				a[r].a=0;
				r--;
			}else if(a[l].a<a[r].a){
				a[r].a-=a[l].a;
				ans+=a[l].a;
				a[l].a=0;
				l++;
			}else{
				ans+=a[r].a;
				a[r].a=0;
				a[l].a=0;
				l++;
				r--;
			}
		}
		if(len%2==1&&R-L==1){
			break;
		}
	}
	cout<<ans;
	return 0;
}
