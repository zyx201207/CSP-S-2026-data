#include<bits/stdc++.h>
using namespace std;
long long n,a[300000],sum1,sum2,d,ans;
char b[300000],s1,s2;
int f=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0,j=n+1;i<j;){
		if(sum2<sum1){
			sum2+=a[--j];
			s2=b[j];	
		}else{
			sum1+=a[++i];
			s1=b[i];
		}if(s1!=s2){
				ans+=min(sum1,sum2)-d;
			}d=min(sum1,sum2);
	}
	cout<<ans;
	return 0;
} 
