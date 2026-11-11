#include<bits/stdc++.h>
using namespace std;
int n,a[900000005],cnt,k;
char c[900000005],s[900000005],r[900000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%s",a,c);
		for(int j=0;j<a[i];i++)
			s[j]=c[i];
	}
	k=strlen(s);
	for(int i=k;i>=0;i--){
		r[i]=s[i];
	}
	for(int i=0;i<k;i++){
		if(r[i]==s[i]){
			for(int j=i;j<k-1;j++){
				r[i]=s[i];
				cnt++;
			}
			break;
		}
	}
	printf("%d",cnt);
	return 0;
}