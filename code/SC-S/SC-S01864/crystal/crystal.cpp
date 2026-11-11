#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,ans=1;
ll a[N],ch[N];
int lx=1,dc=1;
struct A{
	ll c,l;
}s[N];
bool cmp(A x,A y){
	return x.l>y.l;
}
ll ss[N];
int main(){
	freopen("crystal1.in","r",stdin);
	//freopen("crystal3.out","w",stdout);
	cin>>n>>m;
	//cout<<n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=1){
			lx=0;
		}
	}
	ll cha=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cha)dc=0;
	}
	if(lx){
		//cout<<"lx";
		ll t=1;
		for(int i=n-1;i>=1;i--){
			if(m-t>=0){
				m-=t++;
				ans++;
			}
			else{
				cout<<ans;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	if(dc){
	//	cout<<"dc";
		ll t=cha;
		for(int i=n-1;i>=1;i--){
			if(m-t>=0){
				m-=t+=cha;
				ans++;
			}
			else{
				cout<<ans;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		//cout<<"zc";
		for(int i=1;i<n;i++){
			ch[i]=a[i+1]-a[i];
			//cout<<ch[i]<<endl;
		}
	//	s[1].c=0;5 5
//		for(int i=1;i<=n;i++){
//			s[i].c=s[i-1].c+a[i];
//			s[i].l=s[i-1].l+1;
//		}
		for(int i=1;i<n;i++){
			ss[i]=0;
			for(int j=i;j>=1;j--){
				//cout<<"*";
				if(ss[i]<m){
					s[i].c+=ch[j];
					ss[i]+=s[i].c;
					//cout<<"s["<<i<<"].c::"<<s[i].c<<' ';
					//	cout<<"s["<<i<<"].l::"<<s[i].l<<endl;
					s[i].l++;
				}
				else{
				//	cout<<"(())"<<ss[i]<<endl;
					//break;
				}
			}
		}
		sort(s+1,s+n,cmp);
		cout<<s[1].l;
	}
	return 0;
}