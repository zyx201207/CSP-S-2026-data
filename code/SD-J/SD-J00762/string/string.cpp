#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long num;
char it;
long long ans;
void huiwen(){
	long long l=0,r=s.length()-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		string ls;
		cin>>num>>it;
		int now=1;
		ls+=it;
		while(num!=now){
			if(now*2>num){
				for(int i=0;i<num-now;i++){
					s+=it;
				}
				break;
			}
			if(now%2==0){
				now*=2;
				ls+=ls;
			}else{
				now++;
				ls+=it;
			}
		}
		s+=ls;
	}
	huiwen();
	cout<<ans;
	return 0;
}
