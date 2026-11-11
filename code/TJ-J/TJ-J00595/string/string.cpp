#include <bits/stdc++.h>
using namespace std;
long long n,a[100010],ans=1;
string b;
char c[100100]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
		for(int l=1;l<=a[i];l++){
			c[ans]=b[l];
			ans++;
		}
	}
	long long t=ans-1,s=1,w=t,cnt=0;
	if(t%2==1){
		while(s<=(t-1)/2){
			if(c[s]!=c[w]){
				cnt++;
			}
			s++;
			w--;
		}
	}
	else{
		while(s<=t/2){
			if(c[s]!=c[w]){
				cnt++;
			}
			s++;
			w--;
		}
	}
	cout<<(ans-1)/2;
	return 0;
}		
