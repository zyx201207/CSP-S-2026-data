#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll ans;
	char c;
}a[200010];
ll n,o,as,num;
int main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		ll m;
		char ch;
		cin>>m>>ch;
		if(as==0){
			a[o].ans=m;
			a[o].c=ch;
			as=1;
		}else if(a[o].c==ch){
			a[o].ans+=m;
		}else{
			o++;
			a[o].ans=m;
			a[o].c=ch;
		}
	}
	ll i=0,j=o;
	while(i<j){
		if(a[i].c!=a[j].c){
			if(a[i].ans<a[j].ans){
				num+=a[i].ans;
				a[j].ans-=a[i].ans;
				i++;
			}else if(a[i].ans>a[j].ans){
				num+=a[j].ans;
				a[i].ans-=a[j].ans;
				j--;
			}else{
				num+=a[i].ans;
				i++;
				j--;
			}
		}else{
			if(a[i].ans<a[j].ans){
				a[j].ans-=a[i].ans;
				i++;
			}else if(a[i].ans>a[j].ans){
				a[i].ans-=a[j].ans;
				j--;
			}else{
				i++;
				j--;
			}
		}
	}
	cout<<num;
	return 0;
}
