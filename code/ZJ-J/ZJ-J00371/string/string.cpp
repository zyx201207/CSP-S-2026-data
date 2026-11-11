#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char ch;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
	}
	int l=1,r=n;
	long long cnt=0;
	while(l!=r){
		if(a[l].num<a[r].num){
			if(a[l].ch!=a[r].ch)cnt+=a[l].num;
			a[r].num-=a[l].num;
			l++;
		}
		else{
			if(a[r].ch!=a[l].ch)cnt+=a[r].num;
			a[l].num-=a[r].num;
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
