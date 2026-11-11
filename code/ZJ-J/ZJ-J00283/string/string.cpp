#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,k,p,q;
struct p{
	ll x;
	char c;
}a[N];
string s;
char l[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		s+=a[i].c;
		if(!l[a[i].c]){
			l[a[i].c]++;
			q++;
		}
	}
	if(q==1){
		cout<<0;
		return 0;
	}
	if(int(s.size())%2==1) p=(int(s.size())+1)/2;
	else p=int(s.size())/2;
	for(int i=0;i<s.size();i++){
		if(int(s.size())-1-i<i) break;
		ll cnt=0;
		if(a[i+1].x<a[s.size()-i].x){
			ll sum=0,op=1;
			if(a[i+1].c!=a[s.size()-i].c) sum=a[s.size()-i].x;
			else{
				op++;
				sum=a[s.size()-i].x-a[i+1].x;
			}
			for(int j=i+op;j<=p;j++){
				if(a[j].c==s[i]) continue;
				if(a[j].x>sum){
					a[j].x-=sum;
					k+=sum;
					break;
				}else if(a[j].x<sum){
					cnt++;
					sum-=a[j].x;
					k+=a[j].x;
				}else{
					k+=a[j].x;
					cnt++;
					break;
				}
			}
		}
			else if(a[i+1].x>a[s.size()-i].x){
			ll sum=0,op=i;
			if(a[s.size()-i].c!=a[i+1].c) sum=a[i+1].x;
			else{
				op++;
				sum=a[i+1].x-a[s.size()-i].x;
			}
			for(int j=s.size()-op;j>=p;j--){
				if(a[j].c==s[i]) continue;
				if(a[j].x>sum){
					a[j].x-=sum;
					k+=sum;
					break;
				}else if(a[j].x<sum){
					cnt++;
					sum-=a[j].x;
					k+=a[j].x;
				}else{
					k+=a[j].x;
					cnt++;
					break;
				}
			}
		}else if(s[i]!=s[s.size()-1-i]) k+=a[i+1].x;
		i+=cnt;
	}
	cout<<k;
	return 0;
}
