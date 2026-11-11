#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,a=0,cnt=0,ans=0;
	char c;
	string e;
	cin>>n; 
	
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			e+=c;
		}
		cnt+=a;
		
	}
	int g=cnt;
	if(cnt%2!=0){
		cnt=(cnt+1)/2;
	}
	else{
		cnt=cnt/2;
	}
	for(int i=0;i<cnt;i++){
		if(e[i]!=e[g-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
