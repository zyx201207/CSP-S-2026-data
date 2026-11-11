#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005];
int n;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		scanf("%s",c+i);
		
	}
	


	
		
	}
	
	
	long long cnt=0;
	for(int i=0;i<n;i++){
		if(c[i]==c[n-i-1]&&(n-i-1)>i)
		{
			if(a[i]==a[n-i-1]){
				i=i;
			}
			else if(a[i]<a[n-i-1]&&c[i+1]==c[n-i-1]||a[i]>a[n-i-1]&&c[n-i-2]==c[i]){
				if(a[i]<a[n-i-1]){
					a[i+1]-=max(a[i],a[n-i-1])-min(a[i],a[n-i-1]);
				}
				else{
					a[n-i-1]-=max(a[i],a[n-i-1])-min(a[i],a[n-i-1]);
				}
			}
			else {
				cnt+=max(a[i],a[n-i-1])-min(a[i],a[n-i-1]);
			}
		}
		else{
			cnt+=min(a[i],a[n-i-1]);
		}
	}
	
	cout<<cnt;
	return 0; 
}
