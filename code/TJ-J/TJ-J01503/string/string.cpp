#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int a[200005];
char c[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	long long al=a[l],ar=a[r];
	while(r-l>0){
		if(al!=ar){
			if(al>ar){
				if(c[l]!=c[r]){
					al=al-ar;
					ans+=ar;
					r--;
					ar=a[r];
				}else{
					al-=ar;
					r--;
					ar=a[r];
				}   		   
			}else{
				if(c[l]!=c[r]){
					ar=ar-al;
					ans+=al;
					l++;
					al=a[l];
				}else{
					ar-=al;
					l++;
					al=a[l];
				}   	
			}
		}else{
			if(c[l]!=c[r]){
				ans+=al;
				r--;
				l++;
				al=a[l];
				ar=a[r];
			}else{
				r--;
				l++;
				al=a[l];
				ar=a[r];
			}   
		}	
	}
	cout<<ans;
	return 0;
} 



