#include<bits/stdc++.h>
using namespace std;
int a[200020];
char s[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
    }
    long long sum=0;
    int l=1,r=n;
    while(l<=r){
    	if(s[l]!=s[r]){
    		if(a[l]>a[r]){
    			sum+=a[r];
    			a[l]-=a[r];
    			r--;
			}
			else if(a[r]>a[l]){
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				sum+=a[r];
				l++;
				r--;
			}
		}
		else {
			if(a[l]>a[r]){
    			a[l]-=a[r];
    			r--;
			}
			else if(a[r]>a[l]){
				a[r]-=a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
    	}
	}
	cout<<sum;
	return 0;
} 
