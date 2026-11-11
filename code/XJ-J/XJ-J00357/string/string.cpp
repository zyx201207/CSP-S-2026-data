#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt=0;
	for(int i=0;i<n;i++){
		long long num;
		char c;
		cin>>num>>c;
		for(int j=0;j<num;j++){
			s+=c;
			cnt++;
		}
	}
	long long mid=0,l=0,r=0;
	if(cnt%2){
		mid=cnt/2+1;
		l=mid-1;
		r=mid-1;
	}else{
		mid=cnt/2;
		l=mid-1;
		r=mid;
	}
	long long ans=0;
	while(l>=0&&r<cnt){
		if(s[l]!=s[r]){
			ans++;
		}
		l--;
		r++;
		
	}
	cout<<ans;
	return 0;
}