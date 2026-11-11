#include<bits/stdc++.h>
using namespace std;
char s[200000],s1[200000],s0[200000];
int a[200000],a1[200000],cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0;
	cin>>n;
	for(int i=0,j=n-1;i<n;i++,j--){
		cin>>a[i];
		cnt+=a[i];
		cin>>s[i];
		a1[j]=a[i];
		s1[j]=s[i];
		}
		for(int j=0;j<n;j++){
			for(int i=a[j];i<cnt;i++){
	            if(i<=a[j]&&s[i]!=s1[i]){
	            	k++;
	            	break;
				}
			}
		}
	cout<<k;
	return 0;
}