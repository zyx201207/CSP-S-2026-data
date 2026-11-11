#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],x=0,ma=0,mi=0;
	char s[200005],s1,s2;
	cin>>n;
	for(int ii=1;ii<=n;ii++){
		cin>>a[ii]>>s[ii];
	}
	int j=n,i=1;
	while(i<j){
		if(ma==mi){
			ma+=a[i];
			mi+=a[j];
			s1=s[i];
			s2=s[j];
			if(a[i]==a[j]&&s[i]==s[j]){
				i++;
				j--;
				continue;
			}
			if(a[i]==a[j]){
				i++;
				j--;
				x+=a[i];
				continue;
			}
			if(s[i]==s[j]){
				if(a[i]>a[j]){
					j--;
				}
				else i++;
				continue;
			}
			else {
				if(a[i]>a[j]){
					x+=a[j];
					j--;
				}
				else {
					x+=a[i];
					i++;	
				}
				continue;
			}
		}
		else if(ma>mi){
			if(s[j]==s1){
				mi+=a[j];
			}
			else {
				if(ma>mi+a[j]){
					x+=a[j];
				}
				else {
					x+=(ma-mi);
				}
			}
			j--;
		}
		else if(ma<mi){
			if(s[i]==s2){
				ma+=a[i];
			}
			else {
				if(ma+a[i]<mi){
					x+=a[i];
				}
				else {
					x+=(mi-ma);
				}
			}
			i++;
		}
	}
	cout<<x;
	return 0;
} 
