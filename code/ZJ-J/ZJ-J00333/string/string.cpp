#include<bits/stdc++.h>
using namespace std;
struct node{
	long long len;
	char ch;
}a[200005];
long long n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int l;char c;
		cin>>l>>c;
		a[i].len=l;a[i].ch=c;
	}
	long long leftid=1,rightid=n;
	while(leftid<rightid){
		if(leftid==rightid+1)break;
		if(a[leftid].ch!=a[rightid].ch){
			if(a[leftid].len<a[rightid].len){
				ans+=a[leftid].len;
				a[rightid].len-=a[leftid].len;
				leftid++;
			}
			else if(a[leftid].len==a[rightid].len){
				ans+=a[leftid].len;
				leftid++;
				rightid--;
			}
			else {
				ans+=a[rightid].len;
				a[leftid].len-=a[rightid].len;
				rightid--;
			}
		}
		if(a[leftid].ch==a[rightid].ch){
			if(a[leftid].len<a[rightid].len){
				a[rightid].len-=a[leftid].len;
				leftid++;
			}
			else if(a[leftid].len==a[rightid].len){
				leftid++;
				rightid--;
			}
			else {
				a[leftid].len-=a[rightid].len;
				rightid--;
			}
		}
	}
	cout<<ans;
	return 0;
}