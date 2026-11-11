#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans=0,a[N],b[N],i1,i2,a1,a2;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		b[i]=(c-'a'+1);
	}
	a1=a[1];
	a2=a[n];
	i1=1;
	i2=n;
	while(i1<=i2){
		if(b[i1]==b[i2]){
			if(a1>a2){
				a1-=a2;
				i2--;
				a2=a[i2];
			}
			else if(a1<a2){
				a2-=a1;
				i1++;
				a1=a[i1];
			}
			else if(a1==a2){
				i1++;
				i2--;
				a1=a[i1];
				a2=a[i2];
			}
		}
		else {
			if(a1>a2){
				ans+=a2;
				a1-=a2;
				i2--;
				a2=a[i2];
			}
			else if(a1<a2){
				ans+=a1;
				a2-=a1;
				i1++;
				a1=a[i1];
			}
			else if(a1==a2){
				ans+=a1;
				i1++;
				i2--;
				a1=a[i1];
				a2=a[i2];
			}
		}
	}
	cout<<ans;
    return 0;
}
