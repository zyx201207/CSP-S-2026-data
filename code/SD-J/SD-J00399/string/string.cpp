#include<bits/stdc++.h>
using namespace std;
struct lk{
	long long s;
	char b;
}a[200005];
string q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,sum=0,r=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].b;
		for (int j=r+1;j<=r+a[i].s;j++){
		q+=a[i].b;
		}
		r+=a[i].s;
	}
	long long w;
	if (q.size()%2==0){
		w=q.size();
	}
	else w=q.size()+1;
	for (int i=1;i<=w/2;i++){
		if (q[i]!=q[w-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

