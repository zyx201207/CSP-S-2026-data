#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TIE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N=2e5+5;
int q;
struct node{
	ll n;
	char c;
}a[N];
int tot=1;
ll ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	TIE;
	
	cin>>q;
	cin>>a[1].n>>a[1].c;
	for(int i=2;i<=q;i++){//存储，合并相同的子串 
		ll m;
		char s;
		cin>>m>>s;
		if(s==a[tot].c){
			a[tot].n+=m;
		}
		else{
			a[++tot].n=m;
			a[tot].c=s;
		}
	}
	
	if(tot==1){//只有一个字串时一定回文 
		cout<<0;
		return 0;
	}
	
	int l=1,r=tot;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].n>a[r].n){
				a[l].n-=a[r].n;
				a[r].n=0;
				r--;
			}
			else if(a[l].n<a[r].n){
				a[r].n-=a[l].n;
				a[l].n=0;
				l++;
			}
			else {
				a[l].n=a[r].n=0;
				l++;
				r--;
			}
		}
		else{
			ans+=min(a[l].n,a[r].n);
			if(a[l].n>a[r].n){
				a[l].n-=a[r].n;
				a[r].n=0;
				r--;
			}
			else if(a[l].n<a[r].n){
				a[r].n-=a[l].n;
				a[l].n=0;
				l++;
			}
			else {
				a[l].n=a[r].n=0;
				l++;
				r--;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
/*
2
2 a
3 a

3
2 a
2 b
1 c

3
3 a
3 c
2 a
*/
