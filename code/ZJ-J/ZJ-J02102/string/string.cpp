#include<bits/stdc++.h>
using namespace std;
int n,a[200005],f,i=1;
long long cnt;
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d  %c",&a[i],&c[i]);	
	}
	int t1=a[1],t2=a[n];
	while(n-f!=i&&i<n-f){
		if(c[i]!=c[n-f]){
			if(t1>t2){
				t1-=t2;
				cnt+=t2;
				f++;
				t2=a[n-f];
			}else if(t1<t2){
				t2-=t1;
				cnt+=t1;
				i++;
				t1=a[i];
			}else if(t1==t2){
				cnt+=t2;
				f++;
				t2=a[n-f];
				i++;
				t1=a[i];
			}
		}else{
			if(t1>t2){
				t1-=t2;
				f++;
				t2=a[n-f];
			}else if(t1<t2){
				t2-=t1;
				i++;
				t1=a[i];
			}else if(t1==t2){
			
				f++;
				t2=a[n-f];
				i++;
				t1=a[i];
			}
		}
	}
	cout<<cnt;
	return 0;
}