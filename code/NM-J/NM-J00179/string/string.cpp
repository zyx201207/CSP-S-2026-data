#include<bits/stdc++.h>
using namespace std;
long long n,ans,num,mid,sum;
char type;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num>>type;
		sum+=num;
		while(num--){
			a+=type;
		}
	}
	mid=sum/2;
	for(int i=0;i<mid;i++){
		if(a[i]!=a[sum-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
