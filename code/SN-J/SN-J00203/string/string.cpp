#include<bits/stdc++.h>
using namespace std;
struct st{
	long long lo;
	char c;
};
st str[100005];
long long sum=0,n=0,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>str[i].lo>>str[i].c;
		sum+=str[i].lo;
	}
	int l=0,r=n-1;
	if(str[l].c!=str[r].c){
		cnt+=min(str[l].lo,str[r].lo);
	}
	l++;
	r--;
	long long x=0;
	while(l<=(n-1)/2){
		if(str[l].lo==str[r].lo){
			l++;r--;
			cnt+=str[l].lo;
			continue;
		}
		else if(str[l].lo>str[r].lo&&str[l].c!=str[r+1].c){
			str[l].lo-=str[r].lo;
			x=str[l].lo;
			cnt+=x;
			r++;
		}
		else if(str[l].lo<str[r].lo&&str[l+1].c!=str[r].c){
			str[r].lo-=str[l].lo;
			x=str[r].lo;
			cnt+=x;
			l++;
		}
		l++;
		r--;
	}
	if(sum%2!=0) cnt-=str[n/2].lo;
	cout<<cnt;
	return 0;
} 
