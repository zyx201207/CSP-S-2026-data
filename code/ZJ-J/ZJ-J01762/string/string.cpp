#include<bits/stdc++.h>
using namespace std;
string s;
string ss;
int n;
int a[200005];
char c[200005];
long long l;
long long cnt;
long long cntl,cntr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=1;i<=n;i++){
		cntl+=a[i];
		cntr+=a[n-i+1];
		if((cntl==cntr)&&(a[i]==a[n-i+1])){
			
			if(c[i]!=c[n-i+1]){
				cnt+=a[i]*2;
				a[i]=0;
				a[n-i+1]=0;
			}
		}
		else{
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		
	}
	for(int i=s.size()-1;i>=0;i--){
		ss+=s[i];
	}
	if(s==ss&cnt==0){
		cout<<0;
		return 0;
	}
	if(s==ss){
		cout<<cnt/2;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=ss[i]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}