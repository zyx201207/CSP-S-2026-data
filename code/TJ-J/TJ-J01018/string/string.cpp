#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+10;
long long ans;
struct str{
	long long le;
	char c;
}a[N],b[N],c2[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long h=0;
	string s="";
	for(int i=0;i<n;i++){
		cin>>a[i].le>>a[i].c;
		h+=a[i].le;
		for(int j=0;j<a[i].le;j++){
			s+=a[i].c;
		}
	}
	long long p=s.size();
	if(p%2){
		long long half=(p-1)/2;
		for(int i=0;i<half;i++){
			if(s[i]!=s[h-1-i]){
				ans++;
			}
		}
	}else{
		long long half=p/2;
		for(int i=0;i<half;i++){
			if(s[i]!=s[h-1-i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
