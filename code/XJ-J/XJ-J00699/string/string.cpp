#include<bits/stdc++.h>
using namespace std;
const int N=2e9+10;
int n,a[3000],flag=0;
long long int ans;
char c;
string s;
long long int cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c;
		ans+=a[i];
		if(i>=2){
			if(c!=c-1){
				flag=1;
			}
		}
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	long long int len=s.size();
	if(flag==0){
		cout<<0;
		return 0;
	}
	else{
			int l=0,r=len-1;
			for(int i=1;i<=ans/2;i++){
				if(s[l]!=s[r]){
					cnt++;
				}
				l++,r--;
			}	
	}
	cout<<cnt;
	return 0;
}