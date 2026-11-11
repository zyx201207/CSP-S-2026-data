#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int k;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		sum+=s[i].a;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	long long cnt=sum/2;
	if(sum%2==1){
		cnt++;
	}
	for(int i=1;i<=n;i++){
		if(s[i].a<cnt){
			cnt-=s[i].a;
		}
		else{
			k=i;
			break;
		}
	}
	long long cntl=0,cntr=0;
	for(int i=1;i<k;i++){
		if(s[i].c!=s[k].c and s[i].c!=s[i+n/2+1].c){
			cntl+=s[i].a;
		}
		if(s[i].c==s[i+n/2+1].c){
			cntl+=abs(s[i].a-s[i+n/2+1].a);
		}
	}
	for(int i=k+1;i<=n;i++){
		if(s[i].c!=s[k].c and s[i].c!=s[i-n/2-1].c)
		    cntr+=s[i].a;
	}
	cout<<max(cntl,cntr);
	return 0;
}
