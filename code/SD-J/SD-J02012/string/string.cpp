#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N];
char c[N]; 
int n;
ll l;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	s=" ";
	for(int i=1; i<=n; i++){
		string s1="";
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=1; j<=a[i]; j++){
			s1+=c[i];
		}
		
		s+=s1;
	}
	//cout<<s;
	ll cnt=0;
	for(int i=1; i<=l; i++){
		if(i>(l+1)/2) break;
		if(s[i]!=s[l+1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
} 
//#include<bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//const int N=2e5+10;
//ll a[N];
//char c[N];
//ll pre[N][28];
//int n;
//ll sum,mid;
//ll s[N];
//ll st;
//int main(){
//	freopen("string4.in","r",stdin);
//	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin>>n;
//	for(int i=1; i<=n; i++){
//		cin>>a[i]>>c[i];
//		sum+=a[i];
//		for(int j=1; j<=26; j++){
//			pre[i][j]=pre[i-1][j];
//		}
//		
//		pre[i][c[i]-'a'+1]+=a[i];
//	}
//	for(int i=1; i<=n; i++){
//		s[i]=s[i-1]+a[i];
//		if(s[i]>(sum+1)/2&&st==0){
//			st=i;
//		}
//	}
//	
//	ll ans=0;
//	if(sum&1) mid=(sum+1)/2-1;
//	else mid=sum/2;
//	
//	for(int i=st; i<=n; i++){
//		 
//		char cc=c[i];
//		
//		ll r=s[i];
//		ll l=s[i]-a[i]+1;
//		if(l<=(sum+1)/2+1){
//			l++;
//		}
//		//cout<<l<<" "<<r<<"\n";
//		if(l>r) continue;
//		ll lstl=sum-r+1;
//		ll lstr=sum-l+1;
//		ll belr=lower_bound(s+1,s+1+n,lstr)-s;
//		ll bell=lower_bound(s+1,s+1+n,lstl)-s;
//		//cout<<bell<<" "<<belr<<"\n";
//		ll t=0;
//		if(belr!=bell){
//			t+=pre[belr-1][cc]-pre[bell][cc];
//		}
//		if(belr==bell&&c[bell]==cc){
//			t=t+(lstr-lstl+1);
//		}
//		else{
//			if(c[belr]==cc){
//				t=t+lstr-s[belr-1];
//			}
//			if(c[bell]==cc){
//				t=t+min(s[bell],mid)-lstl+1;
//			}	
//		}
//		
//		ans=ans+(lstr-lstl+1-t);
//	//	cout<<lstl<<" "<<lstr<<" "<<t<<"\n";
//	}
//	cout<<ans;
//	return 0;
//} 
///*
//3
//2 a
//2 b
//1 c
//*/
