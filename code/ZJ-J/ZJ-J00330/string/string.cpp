#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define endl '\n'
const int N=1e6+10;
struct node{
	int num;
	char s;
}a[N],b[N];
string s;
//map<char,int> mp;
int sum;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
//	if(n<=2000){
//		for(int i=1;i<=n;i++){
//			int a; 
//			char c; cin>>a>>c;
//			s+=string(a,c);
//		}
////		cout<<s;
////		cout<<endl;
//		int len=s.size();
//	//	cout<<len/2+1<<endl;
//		for(int i=len/2;i<len;i++){
//			if(s[i]==s[len-i-1]) continue;
//	//		cout<<s[i]<<" ";
//			sum++;
//		}
//		cout<<sum;
//		return 0;
//	}
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
//		cout<<a[i].num<<" "<<a[i].s<<endl;
		if(a[i].s!=a[i-1].s) f=0;
		b[n-i+1].num=a[i].num;
		b[n-i+1].s=a[i].s;
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i].s<<" "<<a[i].num<<endl;
//		cout<<b[i].s<<" "<<b[i].num<<endl;
//	}
	if(f) return cout<<0,0;
	int i=1,j=1;
	int ans=0;
	while(i<=n&&j<=n){
//			cout<<a[i].num<<" "<<b[i].num<<endl;
		if(a[i].s==b[j].s){
			if(a[i].num>=b[j].num){
				a[i].num-=b[j].num;
				j++;
			}
			else{
				b[j].num-=a[i].num;
				i++;
			}
		}
		else{
			if(a[i].num>=b[j].num){
				a[i].num-=b[j].num;
				ans+=b[j].num;
				j++;
			}
			else{
				b[j].num-=a[i].num;
				ans+=a[i].num;
				i++;
			}
		}
	}
//	cout<<ans<<" ";
	cout<<ans/2;
	return 0;
}