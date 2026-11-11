#include <bits/stdc++.h>
using namespace std;
char b[500000];
int a[500000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s1=0,s=0,g=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s1+=a[i];
	}
	if(s%2==0) s1=s1/2;
	else s1=s1/2+1;
	for(int i=1;i<=n;i++){
		s=s+a[i];
		if(s>=s1){
		s=i;
		break;
		}
	}
	for(int i=1;i<s;i++){
		s1-=a[i];
	}
	if(a[s]-((s1-1)*2+1)>0&&b[s]!=b[s-1]){
	g+=a[s]-((s1-1)*2+1);
	}
	else if(a[s]-((s1-1)*2+1)<0&&b[s]!=b[s+1]){
	g+=(s1-1)*2+1-a[s];
	}
    for(int i=1;i<s;i++){
    	for(int j=n;j>s;j--){
    		if(b[i]!=b[j]&&a[i]-a[j]>0){
    			g+=a[j];
    			if(b[i]!=b[j-1]) g+=a[i]-a[j];
			}
			if(b[i]!=b[j]&&a[i]-a[j]<0){
    			g+=a[i];
    			if(b[j]!=b[i+1]) g+=a[j]-a[1];
			}
		}
	}
	n=n/2;
	cout<<(g+1)*n;
	return 0;
} 
