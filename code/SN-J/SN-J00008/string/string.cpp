#include<bits/stdc++.h>
using namespace std;
long long l[200002][2];
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char s;
		cin>>a>>s;
		l[i][0]=a;
		l[i][1]=s-'a';
	}
	long long ans=0;
	long long left=1,right=n,left1=0,right1=l[n][0];
	while(left<=right){
		if(l[left][1]!=l[right][1]){
			long long x = min(l[left][0]-left1,right1);
			ans+=x;
		}
		if(l[left][0]-left1>right1){
			left1+=right1;
			right--;
			right1=l[right][0];
		}
		else if(l[left][0]-left1==right1){
			right--;
			left++;
			right1=l[right][0];
			left1=0;
		}
		else{
			right1-=(l[left][0]-left1);
			left++;
			left1=0;
		}
	}
	cout<<ans;
	return 0;
}
