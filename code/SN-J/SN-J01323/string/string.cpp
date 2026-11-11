#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n,m;
	long long ans[200010]={},cnt=0;
	string s;
	char a,cmt[200010]={};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		ans[i]=m;
		cmt[i]=a;
	}
	long long c=1;
	for(int i=1;i<n;i++){
		if(cmt[i]==cmt[i+1]){
			c++;
		}
	}
	if(c==n){
		cout<<"0";
		return 0;
	}
	if(n%2==0){
		int b=0,b1=1,b2=n;
		while(n>0){
			if(cmt[b1]!=cmt[b2-b]){
				if(ans[b1]>ans[b2-b]){
					cnt+=ans[b2-b];
					ans[b1]-=ans[b2-b];
					b++;
					n--;
					continue;
				}
				if(ans[b1]<ans[b2-b]){
					cnt+=ans[b1];
					ans[b2-b]-=ans[b1];
					b1++;
					n--;
					continue;
				}
				if(ans[b1]==ans[b2-b]){
					cnt+=ans[b2-b];
					ans[b1]-=ans[b2-b];
					b++;
					b1++;
					n-=2;
					continue;
				}
			}
			else{
				b++;
				b1++;
				n-=2;
				continue;
			}
		}
	}
	
	else{
		int b=0,b1=1,b2=n;
		while(n>1){
			if(cmt[b1]!=cmt[b2-b]){
				if(ans[b1]>ans[b2-b]){
					cnt+=ans[b2-b];
					ans[b1]-=ans[b2-b];
					b++;
					n--;
					continue;
				}
				if(ans[b1]<ans[b2-b]){
					cnt+=ans[b1];
					ans[b2-b]-=ans[b1];
					b1++;
					n--;
					continue;
				}
				if(ans[b1]==ans[b2-b]){
					cnt+=ans[b2-b];
					ans[b1]-=ans[b2-b];
					b++;
					b1++;
					n-=2;
					continue;
				}
			}
			else{
				b++;
				b1++;
				n-=2;
				continue;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
