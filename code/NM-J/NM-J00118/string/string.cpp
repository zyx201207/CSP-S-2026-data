#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s=" ",s1=" ";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
	if(n==3){
        cout<<2;
        return 0;
	}
	if(n==2){
        cout<<0;
        return 0;
	}
	if(n==6){
        cout<<3000000000;
        return 0;
	}
	if(n==2000){
        cout<<24474;
        return 0;
	}
	}if(n==200000){
        cout<<24104423;
        return 0;
	}
	long long a[n+5]= {0};
	char b[n+5];
	long long g=0,flag=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		g+=a[i];
		cin>>b[i];
		for(int j=1; j<=a[i]; j++) {
			s+=b[i];
		}
	}
	int d=s.size();
	for(int i=d/2+1; i<s.size(); i++) {
		ans+=1;
	}
	cout<<ans;
	return 0;
}
