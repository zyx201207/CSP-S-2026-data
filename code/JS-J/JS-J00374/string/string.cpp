#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m[200005],sum,mid,cnt,ct=0;
char a[200005];
string b,c,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>a[i];
		for(int j=1;j<=m[i];j++) b+=a[i];
	}//cout<<b;
	if(b.size()%2==0){
		for(int i=0;i<b.size()/2;i++){
			if(b[i]!=b[b.size()-1-i]) cnt++;
		}
	}
	if(b.size()%2==1){
		for(int i=0;i<=b.size()/2;i++){
			if(b[i]!=b[b.size()-1-i]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
