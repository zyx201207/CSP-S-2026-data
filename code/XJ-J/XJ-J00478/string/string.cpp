#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL N=2e5+5;
LL n,a[N],ans;
char c;
string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c;
		for(int j=1;j<=a[i];j++){
			S[i]+=(c-'a');
		}
	}
    string T;
	for(int i=S.size();i>=1;i--){
		T[i]+=(S[i]-'a');
	}
	if(T==S){
		cout<<"0";
		return 0;
	}else{
		for(int i=1;i<=S.size();i++){
			if(T[i]!=S[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
