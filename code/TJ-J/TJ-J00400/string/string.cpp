#include<bits\stdc++.h>
using namespace std;
string s,c;
long long n,a[1001],ans,b;
int main(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int i=1;i<=a[i];i++){
			s=s+c;
		}
	}
	b=s.size()-1;
	if(b%2==0){
		int mid=b/2;
			if(s[1]!=s[s.size()]){
				ans++;
			}
		for(int i=2;i<=s.size()-1;i++){
			if(s[i]!=s[i]+b-i){
				ans++;
			}
			if(i==mid){
				cout<<ans;
			}
			break;
		}
	}
	else{
		int mid=b/2+1;
			if(s[1]!=s[b]){
				ans++;
			}
		for(int i=2;i<=s.size()-1;i++){
			if(s[i]!=s[i]+b-i){
				ans++;
			}
			if(i==mid){
				cout<<ans;
			}
		}
	}
	return 0;
}
