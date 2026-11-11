#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t;
    cin>>t;
    int a[200003];
    char b[200003];
    long long ans=0;
    for(int i=1;i<=t;i++)cin>>a[i]>>b[i];
    for(int i=1,j=t;i<=j;){
        if(a[i]>a[j]){
			if(b[i]==b[j]){
				a[i]-=a[j];
				j--;
			}else{
				ans+=a[i];
				j--;
			}
		}else if(a[i]==a[j]){
			if(b[i]==b[j]){
				j--;
				i++;
			}else{
				ans+=a[j];
				j--;
				i++;
			}
		}else{
			if(b[i]==b[j]){
				a[j]-=a[i];
				i++;
			}else{
				ans+=a[i];
				i++;
			}
	}
}
cout<<ans;
}
