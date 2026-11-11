#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt1=0,cnt2=0,a=0;
	int n=0;
	cin>>n;
	if(n%2==0){
		a=n/2;
	}
	if(n/2==1){
		a=n/2+1;
	}
	long long num[10000005]={0};
	char word[10000005];
	for(int i=1;i<=n;i++){
		cin>>num[i]>>word[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(word[j]==word[i]&&num[j]==num[i]){
				if(j==i||j<i){
					cnt1++;
				}
			}
		}
	}
	cout<<a-cnt1;
	return 0;
}
