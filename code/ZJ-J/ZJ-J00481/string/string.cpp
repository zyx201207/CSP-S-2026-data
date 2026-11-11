#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,ans;
struct node{
	int num;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].num>>a[i].c;
	for(int i=1,j=n;i<j;){
		if(a[i].num<a[j].num){
			if(a[i].c!=a[j].c)ans+=a[i].num;
			a[j].num-=a[i].num;
			a[i].num=0;
			i++;
		}
		else if(a[i].num==a[j].num){
			if(a[i].c!=a[j].c)ans+=a[i].num;
			a[j].num=0;
			a[i].num=0;
			i++;
			j--;
		}
		else{
			if(a[i].c!=a[j].c)ans+=a[j].num;
			a[i].num-=a[j].num;
			a[j].num=0;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
