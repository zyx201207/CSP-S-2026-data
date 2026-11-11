#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
string s;

struct node{
	long long a;
	char c;
}b[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
		for(int j=sum;j<sum+b[i].a;j++){
			s[j]=b[i].c;
		}
		sum+=b[i].a;
	}
	if(sum%2==1){
		sum=sum/2;
		for(int i=1;i<=sum;i++){
			if(s[sum-i]!=s[sum+i]){
				ans+=1;
			}
		}
	}
	if(sum%2==0){
		sum=sum/2-1;
		for(int i=0;i<=sum;i++){
			if(s[sum-i]!=s[sum+i+1]){
				ans+=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
