#include<cstdio>
#include<iostream>
using namespace std;
struct node{
	int len;
	char ch;
}a[200010];
int n;
long long sum[200010],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].ch;
		sum[i]=a[i].len;
		sum[i]+=sum[i-1];
	}
	int l=1,r=n;
	while(l<=r){
		if(l==r){
			cout<<ans;
			return 0;
		}
		if(a[l].len>a[r].len){
			a[l].len-=a[r].len;
			if(a[l].ch!=a[r].ch)
			    ans+=a[r].len;
			r--;
		}else if(a[l].len<a[r].len){
			a[r].len-=a[l].len;
			if(a[l].ch!=a[r].ch)
			    ans+=a[l].len;
			l++;
		}else{
			if(a[l].ch!=a[r].ch)
			    ans+=a[l].len;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
