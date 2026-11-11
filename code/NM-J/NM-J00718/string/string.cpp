#include <bits/stdc++.h> 
using namespace std;
string a="",b="";
int n;
long long sum,num,ans; 
char c;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>c;
		sum+=num;
		while(num--){
			a+=c;
		}	 
	}
	for(int i=sum-1;i>=0;i--){
		b+=a[i];
	}
	for(int i=0;i<=(sum-1+2-1)/2;i++){
		if(a[i]!=b[i]) ans++;
	}
	cout<<ans;
	return 0;
}
