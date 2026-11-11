#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt,num=0,ans=0;
char z;
string hw="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cnt>>z;
		for(long long j=0;j<cnt;j++){
			hw+=z;
		}
		num+=cnt;
	}
	for(long long i=0;i<num;i++){
		if(i!=num/2){
			if(hw[i]!=hw[num-1])ans++;
		}
		else break;
	}
	cout<<ans<<endl;
	return 0;
} 
