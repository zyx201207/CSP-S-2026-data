#include <bits/stdc++.h>
using namespace std;
#define ll long long 
struct stu{
	ll a;
	char d;
};
/*string hy(string a){
	ll l=a.length();
	string b="";
	for(ll i=l-1;i>0;i--){
		b+=a[i];
	}
	return b;
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,a,m;
	char b;
	vector<stu> s;
	//string s="";
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a>>b;
		m+=a;
		
		s.push_back({a,b});
		
		/*for(ll j=0;j<a;j++){
			s+=b;
		}*/
	}
	//cout<<s;
//	string x=s;
//	x=hy(x);
	//cout<<x;
	ll ans=0;
	
	ll ls=0;
	char lc;
	
	for(ll i=0,j=n-1;i<n&&j>=0;){
		if(s[i].d!=s[j].d){
			ls=s[i].a-s[j].a;
			ans+=min(s[i].a,s[j].a);
			if(ls>0){
				s[j].a=0;
				s[i].a=ls;
				lc=s[i].d;
				j--;
			}else if(ls<0){
				s[i].a=0;
				s[j].a=ls;
				lc=s[j].d;
				i++;
			}else{
				s[i].a=0;
				s[j].a=0;
				i++;
				j--;
			}
		}else{
			ls=s[i].a-s[j].a;
			if(ls>0){
				s[j].a=0;
				s[i].a=ls;
				lc=s[i].d;
				j--;
			}else if(ls<0){
				s[i].a=0;
				s[j].a=ls;
				lc=s[j].d;
				i++;
			}else{
				s[i].a=0;
				s[j].a=0;
				i++;
				j--;
			}
		}
		
		/*
		if(ls!=0){
			if(ls>0){
				if(lc!=s[j].d){
					s[j].a-=ls;
					if(s[j].a<0){
						ls=s[j].a*-1;
					}else{
						ls=s[j].a
					}
				}
			}else if(ls<0){
				lc=s[j].d;
			}
		}
		if(s[i].d!=s[j].d){
			ls=s[i].a-s[j].a;
			if(ls>0){
				lc=s[i].d;
			}else if(ls<0){
				lc=s[j].d;
			}
			ans+=min(s[i].a,s[j].a);
		} */
	}
	
	/*ll l=s.length();
	for(ll i=0;i<m;i++){
		if(s[i]!=s[l-1-i]){
			ans++;
		}
	}*/
	cout<<ans;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
