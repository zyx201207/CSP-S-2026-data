#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a1=0,a2,m=0,ans=0;
	char s1,s2[99999]; 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a2);
		cin>>s1;
	    for(int j=a1+1;j<=a2;j++){
	        s2[i]=s1;
	    }
	    a1+=a2;
	}
	if(a1%2==1&&a1!=1){
		m=a1/2;
		for(int i=1;i<=m;i++){
			if(s2[i]!=s2[a1+1-i]){
				ans++;
			}
		}
	}
	else{
		m=a1/2;
		for(int i=1;i<=m;i++){
			if(s2[i]!=s2[a1+1-i]){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
