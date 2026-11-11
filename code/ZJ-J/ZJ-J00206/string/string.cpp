#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
long long a[N];
long long ans=0,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int i=1,j=n;
	long long x1=a[1],x2=0;
	while(i<j){
		if(x1>0){
			x2+=a[j];
			if(s[i]!=s[j]){
				if(x1>x2){
					ans+=x2;
				}
				else{
					ans+=x1;	
				}
			}
			if(x1>x2){
				x1-=x2;
				j--;
				x2=0;
				}
			else{
				x2-=x1;
				i++;
				x1=0;
			}
		}
		else{
			x1+=a[i];
			if(s[i]!=s[j]){
				if(x1>x2){
					ans+=x2;
				}
				else{
					ans+=x1;	
				}
			}
			if(x1>x2){
				x1-=x2;
				j--;
				x2=0;
				}
			else{
				x2-=x1;
				i++;
				x1=0;
			}
		}
	}
	cout<<ans;
	return 0;
}