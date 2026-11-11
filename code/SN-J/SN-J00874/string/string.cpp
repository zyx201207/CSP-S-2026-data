#include<bits/stdc++.h>
using namespace std;

long long n,ans;
int a[200005];
char s[200005];
int head,end;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	head=0;
	end=n-1;
	while(head!=end){
		if(s[head]==s[end]){
			if(a[head]>a[end]){
				
				a[head]=a[head]-a[end];
				end--;
			}else{
				
				a[end]=a[end]-a[head];
				head++;
			}	
		}else{
			if(a[head]>a[end]){
				
				a[head]=a[head]-a[end];
				ans=ans+a[end];
				end--;
			}else{
				
				a[end]=a[end]-a[head];
				ans=ans+a[head];
				head++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
