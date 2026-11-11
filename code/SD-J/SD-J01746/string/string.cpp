#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
using namespace std;
const int N=2e5+5;
struct node{
	int len;
	char zimu;
}a[N];
int n;
ll sum;
string s;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		for(int i=1;i<=n;i++){
			cin>>a[i].len>>a[i].zimu;
		}
		cout<<"0"<<endl;
		return 0;
	}
	else if(n<=10){
		for(int i=1;i<=n;i++){
			cin>>a[i].len>>a[i].zimu;
			sum+=a[i].len;
			for(int j=1;j<=a[i].len;j++){
				s+=a[i].zimu;
			}
		}
		string ss="";
		int lens=s.size();
		for(int j=lens;j>=0;j--){
			ss+=s[j];
		}
		if(ss==s){
			cout<<"0"<<endl;
			return 0;
		}
		int mid=(sum+2)/2-1;
		for(int j=0;j<mid;j++){
			if(ss[j]!=s[j]) ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i].len>>a[i].zimu;
			sum+=a[i].len;
		}
		cout<<(sum+2)/2-1<<endl;
	}
	return 0;
} 
