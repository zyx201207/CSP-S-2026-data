#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0;
long long cnt=0;
char c;
string s="0";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c; 
		cnt+=a;
	}
	int j=cnt;
	long long mid=(cnt+1)/2;
	if(cnt%2==0) mid++;
	for(int i=1;i<=mid-1;i++){
		if(s[j-1]!=s[i]) ans++;
		j--;
	} 
	cout<<ans;
	return 0;
} 

// T2
