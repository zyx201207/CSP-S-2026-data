#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long cnt=0;
long long l=0;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	long long left=1,right=n;
	while(left<=right){
		long long stepmin=min(a[left],a[right]);
		if(c[left]!=c[right]){
			cnt+=stepmin;
		}
		a[left]-=stepmin;a[right]-=stepmin;
		if(a[left]<=0){left++;}
		if(a[right]<=0){right--;}
	}
	cout<<cnt;
	return 0;
}