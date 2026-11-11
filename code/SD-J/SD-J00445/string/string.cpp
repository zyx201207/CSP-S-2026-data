#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fr front
#define fi first
#define se second
#define i64 long long
int n;
string s=" ";
i64 ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		char c;
		cin>>t>>c;
		for(int j=1;j<=t;j++){
			s+=c;
		}
	}
	int len=s.size()-1;
	int mid,mid2;
	if(len%2!=0){
		mid=len/2+1;
		for(int i=mid-1,j=mid+1;i>=1,j<=len;i--,j++){
			if(s[i]!=s[j]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else{
		mid=len/2,mid2=len/2+1;
		for(int i=mid,j=mid2;i>=1,j<=len;i--,j++){
			if(s[i]!=s[j]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
