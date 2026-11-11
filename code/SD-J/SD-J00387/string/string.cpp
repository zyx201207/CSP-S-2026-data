#include<bits/stdc++.h> 
using namespace std;
struct node{
	long long a;
	char s;
}a[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].s;
	}
	int i=1,j=n;
	while(i<j){
		if(a[i].s!=a[j].s){
			if(a[i].a<a[j].a){
				ans+=a[i].a;
				a[j].a-=a[i].a;
				a[i].a=0;
			}else {
				ans+=a[j].a;
				a[i].a-=a[j].a;
				a[j].a=0;
			}
		}else if(a[i].s==a[j].s){
			if(a[i].a<a[j].a){
				a[j].a-=a[i].a;
				a[i].a=0;
			}else {
				a[i].a-=a[j].a;
				a[j].a=0;
			}
		}
		if(a[i].a==0)i++;
		if(a[j].a==0)j--;
	}
	cout<<ans;
	return 0;
}
