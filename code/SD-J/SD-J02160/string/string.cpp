#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int T;
pair<signed,char>a[200010];
int b[200010];
int d[200010];
char c[200010];
signed main(){
	fast;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	bool bl=0;
	cin>>a[1].first>>a[1].second;
	b[1]=a[1].first+b[0];
	for (int i=2;i<=T;i++){
		cin>>a[i].first>>a[i].second;
		b[i]=a[i].first+b[i-1];
		if (a[i].second!=a[i-1].second) bl=1;
	} 
	if (bl==0){
		cout<<0;
		return 0;
	}
	int j=1;
	for (int i=1;i<=b[T];i++){
		if (i>=b[j-1] && i<b[j]) c[i]=a[j].second;
		else if (i<b[j-1]) j--,c[i]=a[j].second;
		else if (i>=b[j]) j++,c[i]=a[j].second;
	}
	int cnt=0;
	int l=1,r=b[T];
	while (l<r){
		if (c[l]!=c[r]) cnt++;
		l++,r--;
	}
	cout<<cnt;
	return 0;
}

