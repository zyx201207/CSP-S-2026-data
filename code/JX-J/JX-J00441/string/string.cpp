#include<bits/stdc++.h>
using namespace std;
long long n,num[200010],ans=0,head,tail;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		cin>>s[i];
	}head=1;tail=n;
	while(tail-head!=0){
		if(s[tail]!=s[head]){
			if(num[head]>num[tail]){ans+=num[tail];num[head]-=num[tail];tail--;}
			else if(num[head]<num[tail]){ans+=num[head];num[tail]-=num[head];head++;}
			else {ans+=num[head];if(tail-head==1) break;head++;tail--;}
		}else {
			if(num[head]>num[tail]){num[head]-=num[tail];tail--;}
			else if(num[head]<num[tail]){num[tail]-=num[head];head++;}
			else {if(tail-head==1) break;head++;tail--;}
		}
	}cout<<ans;
	return 0;
}
