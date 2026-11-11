#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e9+10;
ll n,L,cnt;
bool f;
char ch[N];
struct node{
	ll len,sum;
	char c;
}a[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		for(ll j=L+1;j<=L+1+a[i].len;j++){
			ch[j]=a[i].c;
		}
		L+=a[i].len;
		a[i].sum=L;
	}
	f=0;
	for(ll i=1;i<=L/2;i++){
		if(ch[i]!=ch[L-i+1]){
			f=1;
			break;
		}
	}
	if(f==0){
		cout<<"0";
		return 0;
	}
	else{
		for(ll i=1;i<=L/2;i++){
			if(ch[i]!=ch[L-i+1]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
