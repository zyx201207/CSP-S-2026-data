#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
struct node{
	ll a;
	string s1;
}ss[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>ss[i].a>>ss[i].s1;
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=ss[i].a;j++){
			s+=ss[i].s1;
		}
	}
	ll len=s.size();
	if(len%2==0){
		ll l=len/2-1,r=len/2;
		ll sum=0;
		while(l>0&&r<len){
			if(s[l]!=s[r]){
				sum++;
			}
			l--;
			r++;
		}
		cout<<sum;
	}else{
		ll l=len/2,r=len/2;
		ll sum=0;
		while(l>=0&&r<len){
			if(s[l]!=s[r]){
				sum++;
			}
			l--;
			r++;
		}
		cout<<sum;
	}
	return 0;
} 
