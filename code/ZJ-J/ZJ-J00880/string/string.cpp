#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans;
struct Node{
	int num;
	char c;
}a[N],b[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		int j=n-i+1;
		b[j].num=a[i].num,b[j].c=a[i].c;
	}
	for(int i=1,j=1;i<=n;){
//		cout<<i<<' '<<j<<' '<<ans<<"  "<<a[i].num<<' '<<a[i].c<<"  "<<b[j].num<<' '<<b[j].c<<'\n';
		if(a[i].num<b[j].num){
			if(a[i].c!=b[j].c)
				ans+=a[i].num;
			b[j].num-=a[i].num;
			i++;
		}else if(a[i].num>b[j].num){
			if(a[i].c!=b[j].c)
				ans+=b[j].num;
			a[i].num-=b[j].num;
			j++;
		}else{
			if(a[i].c!=b[j].c)
				ans+=a[i].num;
			i++,j++;
		}
	}
	cout<<ans/2;
	return 0;
}
