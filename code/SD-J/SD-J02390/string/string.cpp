#include<bits/stdc++.h>
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
//Ô¼60+£¨10£©·Ö 
const int N=2e5+5;
using namespace std;
struct node{
	ll num;
	char word;
}q[N];
char le[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	CLOSE
	
	cin>>n;
	
	ll all=0;
	
	for(int i=1;i<=n;i++){
		cin>>q[i].num>>q[i].word;
		for(ll j=all+1;j<=all+q[i].num;j++){
			le[j]=q[i].word;
		}
		all+=q[i].num;
	}
	ll cnt=0;
	for(ll i=1;i<=all/2;i++){
		if(le[i]!=le[all-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

