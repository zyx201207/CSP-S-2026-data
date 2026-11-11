#include<bits/stdc++.h>
using namespace std;
const long long N=1e9+5;
long long gay=0;
long long cnt=0;
char s[N];
int gm[N];
char dio[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>gm[i];
		cin>>dio[i];
		for(int j=cnt+1;j<=cnt+gm[i];j++){
			s[j]=dio[i];
		}
		cnt+=gm[i];
	}
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			if(s[i]!=s[j]) gay++;
		}
	}
	if(gay==0){
		cout<<"0";
		return 0;
	}
	long long ans=0;
	if(cnt%2==0){
		long long mid=cnt/2;
		long long r=mid+1;
		long long l=mid;
		while(l>=1){
			if(l!=r) ans++;
			r++;
			l--;
		}
	}else{
		long long mid=cnt/2+1;
		long long r=mid+1;
		long long l=mid-1;
		while(l>=1){
			if(l!=r) ans++;
			r++;
			l--;
		}
	}
	cout<<ans;
	return 0;
}
