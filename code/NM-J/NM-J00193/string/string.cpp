#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,a[N],z,cnt;
char c;
string s;
bool ishw(string x){
	int ans=0;
	for(int i=0;i<n;i++){
		if(s[i]==s[n-i]) ans++;
	}
//	cout<<ans<<endl;
	if(ans>=s.size()/2) return true;
	return false;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		while(a[i]--){
			s+=c;
		}
	}
	z=s.size();
	if(ishw(s)){
		cout<<"0";
		return 0;
	}
//	cnt=*min_element(a,a+n);
//	cout<<cnt*2;
	if(z%2==0){
		for(int i=0;i<z/2;i++){
			for(int j=z;j>z/2;j--){
				if(ishw(s)){
					break;
				}
				if(s[i]!=s[j]){
					s[j]=s[i];
					cnt++;
				}
			}
		}
		cout<<cnt;
		return 0;
	}else{
		for(int i=0;i<z/2;i++){
			for(int j=z-1;j>z/2;j--){
				if(ishw(s)){
					break;
				}
				if(s[i]!=s[j]){
					s[j]=s[i];
					cnt++;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
} 
