#include<bits/stdc++.h>//48pts 暴力模拟n^2+n 
using namespace std;
#define ll long long
ll i,j;
ll n,m;
ll a[500005];
ll cc[500005];

int main(){
	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	ll x=-1;
	ll mmm=n;
	for(i=0;i<n;i++){
		string s="";
		for(j=i;j<n;j++){
			if(s.find(char(a[j]+48))!=s.npos){
				ll y=s.find(char(a[j]+48));
				s.erase(y,n-1);
			}
			s+=a[j]+48;
//			cout<<s<<endl;
		}
//		cout<<s<<endl;
		for(j=1;j<=m;j++){
			if(s.find(char(j+48))!=s.npos){
			    cc[j]++;
		    }
		}
	}
	for(i=1;i<=m;i++)cout<<cc[i]<<" ";
	return 0;
}
//傻逼吧我靠 stack的push运行不了 to_string运行不了 傻逼编译器回家睡觉吧 
