#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,l,r,sum;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int i=1;
	while(n--){
		cin>>a[i]>>s[i];
		sum+=a[i];
		i++;
	}
	l=1,r=i;
	long long cnt=0;
	while(sum&&sum!=1&&l!=r){
		int minn=min(a[l],a[r]);
		if(s[l]!=s[r]){
			cnt+=minn;
			
		}
		sum-=minn*2;
		a[l]-=minn;
		if(a[l]==0)	l++;
		a[r]-=minn;
		if(a[r]==0)	r--;
	}
	cout<<cnt;
	return 0;
} 
